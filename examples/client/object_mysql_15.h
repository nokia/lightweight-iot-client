
#define ResourceLength_15  15
#define ResourceString_15  25

struct ResourceObject_15 {
   short     active;
   short     object;
   short     instances;
   int       resources[ResourceLength_15];
   char      type[ResourceLength_15];
   char      value[ResourceLength_15][ResourceString_15];
};

struct  ResourceObject_15 ro_15;

void Resource_15_Object_Config() {
      
   ro_15.active      = 1;
   ro_15.object      = 10278;
   ro_15.instances   = 1;
   
   memcpy(ro_15.resources, (int[])  {
      6011,6012,6013,6014,6015,6016,6017,6018,6019,6020,6021,6022,6023,6024,6025
   }, sizeof ro_15.resources);
   
   memcpy(ro_15.type, (char[])  {
       'i','b','b','s','i','s','i','i','i','t','t','e','b','i','s'
   }, sizeof ro_15.type);

   char vl[ResourceLength_15][ResourceString_15] = {
       "106","false","false","1","2","3","4","5","6","t","t","e","true","7","0"      
   };
   
   for (int i=0; i < ResourceLength_15; i++) {
      strcpy(ro_15.value[i], vl[i]);
   };
   
}

