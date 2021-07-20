
#define ResourceLength_7  15
#define ResourceString_7  25

struct ResourceObject_7 {
   short     active;
   short     object;
   short     instances;
   int       resources[ResourceLength_7];
   char      type[ResourceLength_7];
   char      value[ResourceLength_7][ResourceString_7];
};

struct  ResourceObject_7 ro_7;

void Resource_7_Object_Config() {
      
   ro_7.active      = 1;
   ro_7.object      = 10270;
   ro_7.instances   = 1;
   
   memcpy(ro_7.resources, (int[])  {
      6000,6001,6002,6003,6004,6005,6006,6007,6008,6009,6010,6026,6027,6028,6029
   }, sizeof ro_7.resources);
   
   memcpy(ro_7.type, (char[])  {
       'i','i','s','t','t','t','t','b','e','o','e','e','e','i','o'
   }, sizeof ro_7.type);

   char vl[ResourceLength_7][ResourceString_7] = {
       "104","1","2","t","t","t","t","false","e","0","e","e","e","9","0"      
   };
   
   for (int i=0; i < ResourceLength_7; i++) {
      strcpy(ro_7.value[i], vl[i]);
   };
   
}

