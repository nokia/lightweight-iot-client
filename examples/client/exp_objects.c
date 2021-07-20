
#include <stdio.h>
#include <string.h>

#define ResourceLength 5

struct ResourceObject {
   short     active;
   short     object;
   short     instances;
   int       resources[ResourceLength];
   char      type[ResourceLength];
   char      value[ResourceLength][25];
};

struct  ResourceObject ro_1;

void Resource_1_Object_Config() {
      
   ro_1.active      = 1;
   ro_1.object      = 10266;
   ro_1.instances   = 1;
   
   memcpy(ro_1.resources, (int[])  {
     6000,6002,6003,6004
   }, sizeof ro_1.resources);
   
   memcpy(ro_1.type, (char[])  {
     'i', 'i', 'd', 'i'
   }, sizeof ro_1.type);

   char str[ResourceLength][25] = { 
     "10", "50", "15", "45"
   };
   
   for (int i=0; i < ResourceLength; i++) {
      strcpy(ro_1.value[i], str[i]);
   }
}



short main () {

   Resource_1_Object_Config();

   int length = sizeof(ro_1.resources) / sizeof(int);

   printf("ro.size         = %d\n", length);   
   printf("ro.object       = %d\n", ro_1.object);   
   printf("ro.resources[2] = %d\n", ro_1.resources[2]);
   printf("ro.type[2]      = %c\n", ro_1.type[2]);
   printf("ro.value[2]     = %s\n", ro_1.value[2]);   

}
