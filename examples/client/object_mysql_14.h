
#define ResourceLength_14  15
#define ResourceString_14  25

struct ResourceObject_14 {
   short     active;
   short     object;
   short     instances;
   int       resources[ResourceLength_14];
   char      type[ResourceLength_14];
   char      value[ResourceLength_14][ResourceString_14];
};

struct  ResourceObject_14 ro_14;

void Resource_14_Object_Config() {
      
   ro_14.active      = 1;
   ro_14.object      = 10277;
   ro_14.instances   = 1;
   
   memcpy(ro_14.resources, (int[])  {
      6011,6012,6013,6014,6015,6016,6017,6018,6019,6020,6021,6022,6023,6024,6025
   }, sizeof ro_14.resources);
   
   memcpy(ro_14.type, (char[])  {
       'i','b','b','s','i','s','i','i','i','t','t','e','b','i','s'
   }, sizeof ro_14.type);

   char vl[ResourceLength_14][ResourceString_14] = {
       "105","false","false","1","2","3","4","5","6","t","t","e","true","7","0"      
   };
   
   for (int i=0; i < ResourceLength_14; i++) {
      strcpy(ro_14.value[i], vl[i]);
   };
   
}

