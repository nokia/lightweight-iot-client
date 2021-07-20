
#define ResourceLength_3  15
#define ResourceString_3  25

struct ResourceObject_3 {
   short     active;
   short     object;
   short     instances;
   int       resources[ResourceLength_3];
   char      type[ResourceLength_3];
   char      value[ResourceLength_3][ResourceString_3];
};

struct  ResourceObject_3 ro_3;

void Resource_3_Object_Config() {
      
   ro_3.active      = 1;
   ro_3.object      = 10266;
   ro_3.instances   = 1;
   
   memcpy(ro_3.resources, (int[])  {
      6000,6001,6002,6003,6004,6005,6006,6007,6008,6009,6010,6026,6027,6028,6029
   }, sizeof ro_3.resources);
   
   memcpy(ro_3.type, (char[])  {
       'i','i','s','t','t','t','t','b','e','o','e','e','e','i','o'
   }, sizeof ro_3.type);

   char vl[ResourceLength_3][ResourceString_3] = {
       "100","1","2","t","t","t","t","false","e","0","e","e","e","9","0"      
   };
   
   for (int i=0; i < ResourceLength_3; i++) {
      strcpy(ro_3.value[i], vl[i]);
   };
   
}

