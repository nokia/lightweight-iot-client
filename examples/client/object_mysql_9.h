
#define ResourceLength_9  15
#define ResourceString_9  25

struct ResourceObject_9 {
   short     active;
   short     object;
   short     instances;
   int       resources[ResourceLength_9];
   char      type[ResourceLength_9];
   char      value[ResourceLength_9][ResourceString_9];
};

struct  ResourceObject_9 ro_9;

void Resource_9_Object_Config() {
      
   ro_9.active      = 1;
   ro_9.object      = 10272;
   ro_9.instances   = 1;
   
   memcpy(ro_9.resources, (int[])  {
      6011,6012,6013,6014,6015,6016,6017,6018,6019,6020,6021,6022,6023,6024,6025
   }, sizeof ro_9.resources);
   
   memcpy(ro_9.type, (char[])  {
       'i','b','b','s','i','s','i','i','i','t','t','e','b','i','s'
   }, sizeof ro_9.type);

   char vl[ResourceLength_9][ResourceString_9] = {
       "100","false","false","1","2","3","4","5","6","t","t","e","true","7","0"      
   };
   
   for (int i=0; i < ResourceLength_9; i++) {
      strcpy(ro_9.value[i], vl[i]);
   };
   
}

