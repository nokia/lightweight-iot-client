
#define ResourceLength_5  15
#define ResourceString_5  25

struct ResourceObject_5 {
   short     active;
   short     object;
   short     instances;
   int       resources[ResourceLength_5];
   char      type[ResourceLength_5];
   char      value[ResourceLength_5][ResourceString_5];
};

struct  ResourceObject_5 ro_5;

void Resource_5_Object_Config() {
      
   ro_5.active      = 1;
   ro_5.object      = 10268;
   ro_5.instances   = 1;
   
   memcpy(ro_5.resources, (int[])  {
      6000,6001,6002,6003,6004,6005,6006,6007,6008,6009,6010,6026,6027,6028,6029
   }, sizeof ro_5.resources);
   
   memcpy(ro_5.type, (char[])  {
       'i','i','s','t','t','t','t','b','e','o','e','e','e','i','o'
   }, sizeof ro_5.type);

   char vl[ResourceLength_5][ResourceString_5] = {
       "102","1","2","t","t","t","t","false","e","0","e","e","e","9","0"      
   };
   
   for (int i=0; i < ResourceLength_5; i++) {
      strcpy(ro_5.value[i], vl[i]);
   };
   
}

