//
//
//
// gcc myget.c -o myget -l sqlite3
// 
// 
// 

#include <sqlite3.h>

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>


double read_analog_input_db(void);

int main(int argc, char *argv[])
{

    double analog_input = 0;   
    analog_input = read_analog_input_db();

    printf("retval : %f\n",analog_input);
}


double read_analog_input_db() {

   int i;
   sqlite3 *db;
   sqlite3_stmt *res;
   char metric_val[30];

   double result = -100;

   // connect to the backend
   int rc = sqlite3_open("database.sqlite3", &db);

   if (rc != SQLITE_OK) {
      fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
      sqlite3_close(db);
      return -100;
   }
            
   // select sensor_value from sensors order by sensor_id desc limit 1
   rc = sqlite3_prepare_v2(db, "select sensor_value from sensors order by sensor_id desc limit 1", -1, &res, 0);
   
   if (rc != SQLITE_OK) {
     fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
     sqlite3_close(db);
     return -100;
   }
   
   rc = sqlite3_step(res);
   
   if (rc == SQLITE_ROW) {
      
     fprintf(stdout, "metric value: %s\n", sqlite3_column_text(res, 0));
      
     result = sqlite3_column_double(res, 0);      
      
     sqlite3_finalize(res);
     sqlite3_close(db);
   }

   return result;
}
   