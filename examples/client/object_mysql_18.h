
#define ResourceLength_18  15
#define ResourceString_18  25

struct ResourceObject_18 {
   short     active;
   short     object;
   short     instances;
   int       resources[ResourceLength_18];
   char      type[ResourceLength_18];
   char      value[ResourceLength_18][ResourceString_18];
};

struct  ResourceObject_18 ro_18;

void Resource_18_Object_Config() {
      
   ro_18.active      = 1;
   ro_18.object      = 10281;
   ro_18.instances   = 1;
   
   memcpy(ro_18.resources, (int[])  {
      6011,6012,6013,6014,6015,6016,6017,6018,6019,6020,6021,6022,6023,6024,6025
   }, sizeof ro_18.resources);
   
   memcpy(ro_18.type, (char[])  {
       'i','b','b','s','i','s','i','i','i','t','t','e','b','i','s'
   }, sizeof ro_18.type);

   char vl[ResourceLength_18][ResourceString_18] = {
       "109","false","false","1","2","3","4","5","6","t","t","e","true","7","0"      
   };
   
   for (int i=0; i < ResourceLength_18; i++) {
      strcpy(ro_18.value[i], vl[i]);
   };
   
}

