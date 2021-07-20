
#define ResourceLength_11  15
#define ResourceString_11  25

struct ResourceObject_11 {
   short     active;
   short     object;
   short     instances;
   int       resources[ResourceLength_11];
   char      type[ResourceLength_11];
   char      value[ResourceLength_11][ResourceString_11];
};

struct  ResourceObject_11 ro_11;

void Resource_11_Object_Config() {
      
   ro_11.active      = 1;
   ro_11.object      = 10274;
   ro_11.instances   = 1;
   
   memcpy(ro_11.resources, (int[])  {
      6011,6012,6013,6014,6015,6016,6017,6018,6019,6020,6021,6022,6023,6024,6025
   }, sizeof ro_11.resources);
   
   memcpy(ro_11.type, (char[])  {
       'i','b','b','s','i','s','i','i','i','t','t','e','b','i','s'
   }, sizeof ro_11.type);

   char vl[ResourceLength_11][ResourceString_11] = {
       "102","false","false","1","2","3","4","5","6","t","t","e","true","7","0"      
   };
   
   for (int i=0; i < ResourceLength_11; i++) {
      strcpy(ro_11.value[i], vl[i]);
   };
   
}

