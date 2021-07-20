
#define ResourceLength_6  15
#define ResourceString_6  25

struct ResourceObject_6 {
   short     active;
   short     object;
   short     instances;
   int       resources[ResourceLength_6];
   char      type[ResourceLength_6];
   char      value[ResourceLength_6][ResourceString_6];
};

struct  ResourceObject_6 ro_6;

void Resource_6_Object_Config() {
      
   ro_6.active      = 1;
   ro_6.object      = 10269;
   ro_6.instances   = 1;
   
   memcpy(ro_6.resources, (int[])  {
      6000,6001,6002,6003,6004,6005,6006,6007,6008,6009,6010,6026,6027,6028,6029
   }, sizeof ro_6.resources);
   
   memcpy(ro_6.type, (char[])  {
       'i','i','s','t','t','t','t','b','e','o','e','e','e','i','o'
   }, sizeof ro_6.type);

   char vl[ResourceLength_6][ResourceString_6] = {
       "103","1","2","t","t","t","t","false","e","0","e","e","e","9","0"      
   };
   
   for (int i=0; i < ResourceLength_6; i++) {
      strcpy(ro_6.value[i], vl[i]);
   };
   
}

