
#define ResourceLength_12  15
#define ResourceString_12  25

struct ResourceObject_12 {
   short     active;
   short     object;
   short     instances;
   int       resources[ResourceLength_12];
   char      type[ResourceLength_12];
   char      value[ResourceLength_12][ResourceString_12];
};

struct  ResourceObject_12 ro_12;

void Resource_12_Object_Config() {
      
   ro_12.active      = 1;
   ro_12.object      = 10275;
   ro_12.instances   = 1;
   
   memcpy(ro_12.resources, (int[])  {
      6011,6012,6013,6014,6015,6016,6017,6018,6019,6020,6021,6022,6023,6024,6025
   }, sizeof ro_12.resources);
   
   memcpy(ro_12.type, (char[])  {
       'i','b','b','s','i','s','i','i','i','t','t','e','b','i','s'
   }, sizeof ro_12.type);

   char vl[ResourceLength_12][ResourceString_12] = {
       "103","false","false","1","2","3","4","5","6","t","t","e","true","7","0"      
   };
   
   for (int i=0; i < ResourceLength_12; i++) {
      strcpy(ro_12.value[i], vl[i]);
   };
   
}

