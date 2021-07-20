
#define ResourceLength_20  15
#define ResourceString_20  25

struct ResourceObject_20 {
   short     active;
   short     object;
   short     instances;
   int       resources[ResourceLength_20];
   char      type[ResourceLength_20];
   char      value[ResourceLength_20][ResourceString_20];
};

struct  ResourceObject_20 ro_20;

void Resource_20_Object_Config() {
      
   ro_20.active      = 1;
   ro_20.object      = 10283;
   ro_20.instances   = 1;
   
   memcpy(ro_20.resources, (int[])  {
      6011,6012,6013,6014,6015,6016,6017,6018,6019,6020,6021,6022,6023,6024,6025
   }, sizeof ro_20.resources);
   
   memcpy(ro_20.type, (char[])  {
       'i','b','b','s','i','s','i','i','i','t','t','e','b','i','s'
   }, sizeof ro_20.type);

   char vl[ResourceLength_20][ResourceString_20] = {
       "111","false","false","1","2","3","4","5","6","t","t","e","true","7","0"      
   };
   
   for (int i=0; i < ResourceLength_20; i++) {
      strcpy(ro_20.value[i], vl[i]);
   };
   
}

