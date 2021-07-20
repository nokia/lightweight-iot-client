// sensor_driver.c
// 
// This source implements the following:
// 
//    Raspberry HAT sensor readout functions
//    Read a coordination file to mimic location data (/6/0/)
// 
// 
// By D.A.Gooris  May 25, 2017     Copyright (C)

#include <sqlite3.h>

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <linux/i2c-dev.h>
#include <pthread.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <math.h>
#include <time.h>
#include <string.h>

#include <sys/time.h>

#include "lwm2mclient.h"
#include "sensor_driver.h"


void   delay(int);
void   startAnalogInputThread(int);
void  *startanalog_inputwiththread(void *);
void   updateChange(int,int, int, char *);
int    queryDatabase(char *);
int    getRecords(void);

// Start the sensor threads here
int startSensorThreads(void) {

    int index = 0;

    // Start the analog_input thread
    startAnalogInputThread(index++);
   
    return (0);
}

int getRecords() {

   char query[255];
  
   sprintf(query,"select object,instance,resource,value from sensors where upd='1' and snid='%s';",GLserialnumber);
  
   return queryDatabase(query);
     
}

int  queryDatabase(char *query) {

   sqlite3 *db;
   sqlite3_stmt *res;
   char   metric_val[30];
   int    attempts = 0;
   char   value[25];
   char   dbfile[100];
   bool   error   = false;
   bool   verbose = false;   
   int    rc = 0;
   int    rows = 0;
   int    i = 0;
   int    object, instance, resource;
   char   reset[255];
   
   strcpy(dbfile,"./sqlite3/database.sqlite3");

   // connect to the backend

   error = false;
   verbose = false;
   for (attempts = 0; attempts < 5; attempts++) {

      rc = sqlite3_open(dbfile, &db);
   
      if (rc != SQLITE_OK) {
         fprintf(stderr, "[%d] - Cannot open database: %s  (file: %s)\n", attempts, sqlite3_errmsg(db),dbfile);
         sqlite3_close(db);
         delay(1000);	 
         error = true;
         verbose = true;
	 continue;
      }
   
      error = false;;
      
      rc = sqlite3_prepare_v2(db, query, -1, &res, 0);   
      if (rc != SQLITE_OK) {
               
        fprintf(stderr, "[%d] - Failed to fetch data: %s\n", attempts, sqlite3_errmsg(db));
        sqlite3_finalize(res);
        sqlite3_close(db);
        delay(1000);
        error = true;	
        verbose = true;
        continue;	 
      } else {
	 
	// All ok, do the rest
        error = false;
        break;
      }
      
   }

   if (error == true) {
      fprintf(stderr, "[%d] - Too many attempts to query database.\n", attempts);
      return 0;
   }

   if (verbose == true) {
      fprintf(stderr, "After [%d] attempts, access to database succeeded\n", attempts);
   }
      
   rows = 0;
   while (true) {
	
      rc = sqlite3_step(res);
  
      if (rc == SQLITE_ROW) { 
	   
         object   = sqlite3_column_int(res, 0);
         instance = sqlite3_column_int(res, 1);
         resource = sqlite3_column_int(res, 2);	 
         strcpy(value,sqlite3_column_text(res, 3));

         updateChange(object,instance,resource,value);
	 
      } else {
	 break;
      }
      
      rows++;
      
      if (rows > 100) {
	   break;
      }
      
   }

   
   sqlite3_finalize(res);
   
   // Reset the value in the database
   if (rows > 0) {	
      sprintf(reset,"update sensors set upd='0' where snid='%s';",GLserialnumber);
      // printf("Query: %s\n\r",reset);
      
      rc = sqlite3_prepare_v2(db, reset, -1, &res, 0);   
      if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to reset the data: %s\n", sqlite3_errmsg(db));
      } else {
         rc = sqlite3_step(res);
      }
      
   }
   
   sqlite3_finalize(res);
   
   sqlite3_close(db);
	  
   // printf("Sqlite read result: obj/%d/%d ->  %f\n", instance,resource,result);
   
   return rows;
}


void updateChange(int object,int instance, int resource, char *value){

   lwm2m_uri_t uri;       
   int len = 0;
   char url[25];
   
   sprintf(url,"/%d/%d/%d",object,instance,resource);
   len = strlen(url);

   switch (object)   {
      
#include "a2.h"
         
      default:
           break;	
   }
      
   if (lwm2m_stringToUri(url, len, &uri)) {
      lwm2m_resource_value_changed(GLlwm2mH, &uri);
      printf(" ->%s Object %s --> %s  changed\r\n",YELLOW,url,value);
      printf("%s",NORMAL);
      fflush(stdout);
   }

}
   
void startAnalogInputThread(int index) {
  
    int retval = 0;
   
    // Threading
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
    pthread_attr_setstacksize(&attr,102400);
      
    retval = pthread_create(&GLthread[index], &attr, (void *)startanalog_inputwiththread, (void *)intpointers[index]);
   
    if ( retval != 0 ) {
       printf("startAnalogInputThread() - not able to start a thread for the request for index=%d\n",index);
       fflush(stdout);
       return;
    }
}

void *startanalog_inputwiththread(void *data) {
   
    int   *indexptr = (int *)data;
    int   index;
   
    // Restore the argument
    index=*indexptr;
   
    int   wait = 1000;
    int   instance;
   
    // One second loop
    while (1) {
       
       delay(wait);       
       getRecords();
       delay(wait);
       delay(wait);
       delay(wait);  
       
    }
      
}

// Print the time in hh:mm:ss.ms
char *gettime(char *p) {

  struct timeval mtime;
  struct tm     *local;
  time_t lt;
  double ms;
  char   str[30];

  // Do the time calculation
  gettimeofday(&mtime, NULL);
  lt = ms = (double)(mtime.tv_sec) + 0.000001 * mtime.tv_usec;
  local = localtime(&lt);

  sprintf(str,"%f",ms);
  sprintf(p,"%4.4d-%2.2d-%2.2d %2.2d:%2.2d:%2.2d%3.4s",local->tm_year+1900,local->tm_mon+1,local->tm_mday,local->tm_hour,local->tm_min,local->tm_sec,str+10);

  return(p);
}

static const long hextable[] = {
   [0 ... 255] = -1,                     // bit aligned access into this table is considerably
   ['0'] = 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, // faster for most modern processors,
   ['A'] = 10, 11, 12, 13, 14, 15,       // for the space conscious, reduce to
   ['a'] = 10, 11, 12, 13, 14, 15        // signed char.
};

long hexdec(unsigned const char *hex) {
   
   long ret = 0; 
   while (*hex && ret >= 0) {
      ret = (ret << 4) | hextable[*hex++];
   }   
   return ret; 
}

void delay(int delay) {   
   usleep(delay * 1000);
}

// End of sensor_driver.c


