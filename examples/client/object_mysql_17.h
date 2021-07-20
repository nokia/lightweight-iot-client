
#define ResourceLength_17  15
#define ResourceString_17  25

struct ResourceObject_17 {
   short     active;
   short     object;
   short     instances;
   int       resources[ResourceLength_17];
   char      type[ResourceLength_17];
   char      value[ResourceLength_17][ResourceString_17];
};

struct  ResourceObject_17 ro_17;

void Resource_17_Object_Config() {
      
   ro_17.active      = 1;
   ro_17.object      = 10280;
   ro_17.instances   = 1;
   
   memcpy(ro_17.resources, (int[])  {
      6011,6012,6013,6014,6015,6016,6017,6018,6019,6020,6021,6022,6023,6024,6025
   }, sizeof ro_17.resources);
   
   memcpy(ro_17.type, (char[])  {
       'i','b','b','s','i','s','i','i','i','t','t','e','b','i','s'
   }, sizeof ro_17.type);

   char vl[ResourceLength_17][ResourceString_17] = {
       "108","false","false","1","2","3","4","5","6","t","t","e","true","7","0"      
   };
   
   for (int i=0; i < ResourceLength_17; i++) {
      strcpy(ro_17.value[i], vl[i]);
   };
   
}

