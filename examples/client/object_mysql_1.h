
#define ResourceLength_1  7
#define ResourceString_1  25

struct ResourceObject_1 {
   short     active;
   short     object;
   short     instances;
   int       resources[ResourceLength_1];
   char      type[ResourceLength_1];
   char      value[ResourceLength_1][ResourceString_1];
};

struct  ResourceObject_1 ro_1;

void Resource_1_Object_Config() {
      
   ro_1.active      = 1;
   ro_1.object      = 3303;
   ro_1.instances   = 1;
   
   memcpy(ro_1.resources, (int[])  {
      5601,5602,5603,5604,5605,5700,5701
   }, sizeof ro_1.resources);
   
   memcpy(ro_1.type, (char[])  {
       'f','f','f','f','e','f','s'
   }, sizeof ro_1.type);

   char vl[ResourceLength_1][ResourceString_1] = {
       "0","0","-10","300","exec","0","Celcius"      
   };
   
   for (int i=0; i < ResourceLength_1; i++) {
      strcpy(ro_1.value[i], vl[i]);
   };
   
}

