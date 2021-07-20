
#define ResourceLength_21  15
#define ResourceString_21  25

struct ResourceObject_21 {
   short     active;
   short     object;
   short     instances;
   int       resources[ResourceLength_21];
   char      type[ResourceLength_21];
   char      value[ResourceLength_21][ResourceString_21];
};

struct  ResourceObject_21 ro_21;

void Resource_21_Object_Config() {
      
   ro_21.active      = 1;
   ro_21.object      = 10284;
   ro_21.instances   = 1;
   
   memcpy(ro_21.resources, (int[])  {
      6011,6012,6013,6014,6015,6016,6017,6018,6019,6020,6021,6022,6023,6024,6025
   }, sizeof ro_21.resources);
   
   memcpy(ro_21.type, (char[])  {
       'i','b','b','s','i','s','i','i','i','t','t','e','b','i','s'
   }, sizeof ro_21.type);

   char vl[ResourceLength_21][ResourceString_21] = {
       "112","false","false","1","2","3","4","5","6","t","t","e","true","7","0"      
   };
   
   for (int i=0; i < ResourceLength_21; i++) {
      strcpy(ro_21.value[i], vl[i]);
   };
   
}

