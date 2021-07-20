
#define ResourceLength_4  15
#define ResourceString_4  25

struct ResourceObject_4 {
   short     active;
   short     object;
   short     instances;
   int       resources[ResourceLength_4];
   char      type[ResourceLength_4];
   char      value[ResourceLength_4][ResourceString_4];
};

struct  ResourceObject_4 ro_4;

void Resource_4_Object_Config() {
      
   ro_4.active      = 1;
   ro_4.object      = 10267;
   ro_4.instances   = 1;
   
   memcpy(ro_4.resources, (int[])  {
      6000,6001,6002,6003,6004,6005,6006,6007,6008,6009,6010,6026,6027,6028,6029
   }, sizeof ro_4.resources);
   
   memcpy(ro_4.type, (char[])  {
       'i','i','s','t','t','t','t','b','e','o','e','e','e','i','o'
   }, sizeof ro_4.type);

   char vl[ResourceLength_4][ResourceString_4] = {
       "101","1","2","t","t","t","t","false","e","0","e","e","e","9","0"      
   };
   
   for (int i=0; i < ResourceLength_4; i++) {
      strcpy(ro_4.value[i], vl[i]);
   };
   
}

