
#define ResourceLength_2  7
#define ResourceString_2  25

struct ResourceObject_2 {
   short     active;
   short     object;
   short     instances;
   int       resources[ResourceLength_2];
   char      type[ResourceLength_2];
   char      value[ResourceLength_2][ResourceString_2];
};

struct  ResourceObject_2 ro_2;

void Resource_2_Object_Config() {
      
   ro_2.active      = 1;
   ro_2.object      = 3304;
   ro_2.instances   = 1;
   
   memcpy(ro_2.resources, (int[])  {
      5601,5602,5603,5604,5605,5700,5701
   }, sizeof ro_2.resources);
   
   memcpy(ro_2.type, (char[])  {
       'f','f','f','f','e','f','s'
   }, sizeof ro_2.type);

   char vl[ResourceLength_2][ResourceString_2] = {
       "0","0","0","100","exec","0","%"      
   };
   
   for (int i=0; i < ResourceLength_2; i++) {
      strcpy(ro_2.value[i], vl[i]);
   };
   
}

