
#define ResourceLength_13  15
#define ResourceString_13  25

struct ResourceObject_13 {
   short     active;
   short     object;
   short     instances;
   int       resources[ResourceLength_13];
   char      type[ResourceLength_13];
   char      value[ResourceLength_13][ResourceString_13];
};

struct  ResourceObject_13 ro_13;

void Resource_13_Object_Config() {
      
   ro_13.active      = 1;
   ro_13.object      = 10276;
   ro_13.instances   = 1;
   
   memcpy(ro_13.resources, (int[])  {
      6011,6012,6013,6014,6015,6016,6017,6018,6019,6020,6021,6022,6023,6024,6025
   }, sizeof ro_13.resources);
   
   memcpy(ro_13.type, (char[])  {
       'i','b','b','s','i','s','i','i','i','t','t','e','b','i','s'
   }, sizeof ro_13.type);

   char vl[ResourceLength_13][ResourceString_13] = {
       "104","false","false","1","2","3","4","5","6","t","t","e","true","7","0"      
   };
   
   for (int i=0; i < ResourceLength_13; i++) {
      strcpy(ro_13.value[i], vl[i]);
   };
   
}

