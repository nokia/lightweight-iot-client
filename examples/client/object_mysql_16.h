
#define ResourceLength_16  15
#define ResourceString_16  25

struct ResourceObject_16 {
   short     active;
   short     object;
   short     instances;
   int       resources[ResourceLength_16];
   char      type[ResourceLength_16];
   char      value[ResourceLength_16][ResourceString_16];
};

struct  ResourceObject_16 ro_16;

void Resource_16_Object_Config() {
      
   ro_16.active      = 1;
   ro_16.object      = 10279;
   ro_16.instances   = 1;
   
   memcpy(ro_16.resources, (int[])  {
      6011,6012,6013,6014,6015,6016,6017,6018,6019,6020,6021,6022,6023,6024,6025
   }, sizeof ro_16.resources);
   
   memcpy(ro_16.type, (char[])  {
       'i','b','b','s','i','s','i','i','i','t','t','e','b','i','s'
   }, sizeof ro_16.type);

   char vl[ResourceLength_16][ResourceString_16] = {
       "107","false","false","1","2","3","4","5","6","t","t","e","true","7","0"      
   };
   
   for (int i=0; i < ResourceLength_16; i++) {
      strcpy(ro_16.value[i], vl[i]);
   };
   
}

