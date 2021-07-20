
#define ResourceLength_19  15
#define ResourceString_19  25

struct ResourceObject_19 {
   short     active;
   short     object;
   short     instances;
   int       resources[ResourceLength_19];
   char      type[ResourceLength_19];
   char      value[ResourceLength_19][ResourceString_19];
};

struct  ResourceObject_19 ro_19;

void Resource_19_Object_Config() {
      
   ro_19.active      = 1;
   ro_19.object      = 10282;
   ro_19.instances   = 1;
   
   memcpy(ro_19.resources, (int[])  {
      6011,6012,6013,6014,6015,6016,6017,6018,6019,6020,6021,6022,6023,6024,6025
   }, sizeof ro_19.resources);
   
   memcpy(ro_19.type, (char[])  {
       'i','b','b','s','i','s','i','i','i','t','t','e','b','i','s'
   }, sizeof ro_19.type);

   char vl[ResourceLength_19][ResourceString_19] = {
       "110","false","false","1","2","3","4","5","6","t","t","e","true","7","0"      
   };
   
   for (int i=0; i < ResourceLength_19; i++) {
      strcpy(ro_19.value[i], vl[i]);
   };
   
}

