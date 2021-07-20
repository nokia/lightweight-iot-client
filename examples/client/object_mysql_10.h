
#define ResourceLength_10  15
#define ResourceString_10  25

struct ResourceObject_10 {
   short     active;
   short     object;
   short     instances;
   int       resources[ResourceLength_10];
   char      type[ResourceLength_10];
   char      value[ResourceLength_10][ResourceString_10];
};

struct  ResourceObject_10 ro_10;

void Resource_10_Object_Config() {
      
   ro_10.active      = 1;
   ro_10.object      = 10273;
   ro_10.instances   = 1;
   
   memcpy(ro_10.resources, (int[])  {
      6011,6012,6013,6014,6015,6016,6017,6018,6019,6020,6021,6022,6023,6024,6025
   }, sizeof ro_10.resources);
   
   memcpy(ro_10.type, (char[])  {
       'i','b','b','s','i','s','i','i','i','t','t','e','b','i','s'
   }, sizeof ro_10.type);

   char vl[ResourceLength_10][ResourceString_10] = {
       "101","false","false","1","2","3","4","5","6","t","t","e","true","7","0"      
   };
   
   for (int i=0; i < ResourceLength_10; i++) {
      strcpy(ro_10.value[i], vl[i]);
   };
   
}

