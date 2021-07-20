
#define ResourceLength_8  15
#define ResourceString_8  25

struct ResourceObject_8 {
   short     active;
   short     object;
   short     instances;
   int       resources[ResourceLength_8];
   char      type[ResourceLength_8];
   char      value[ResourceLength_8][ResourceString_8];
};

struct  ResourceObject_8 ro_8;

void Resource_8_Object_Config() {
      
   ro_8.active      = 1;
   ro_8.object      = 10271;
   ro_8.instances   = 1;
   
   memcpy(ro_8.resources, (int[])  {
      6000,6001,6002,6003,6004,6005,6006,6007,6008,6009,6010,6026,6027,6028,6029
   }, sizeof ro_8.resources);
   
   memcpy(ro_8.type, (char[])  {
       'i','i','s','t','t','t','t','b','e','o','e','e','e','i','o'
   }, sizeof ro_8.type);

   char vl[ResourceLength_8][ResourceString_8] = {
       "105","1","2","t","t","t","t","false","e","0","e","e","e","9","0"      
   };
   
   for (int i=0; i < ResourceLength_8; i++) {
      strcpy(ro_8.value[i], vl[i]);
   };
   
}

