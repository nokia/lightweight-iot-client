
#define ResourceLength__FILEINDEX_  _RESOURCES_
#define ResourceString__FILEINDEX_  25

struct ResourceObject__FILEINDEX_ {
   short     active;
   short     object;
   short     instances;
   int       resources[ResourceLength__FILEINDEX_];
   char      type[ResourceLength__FILEINDEX_];
   char      value[ResourceLength__FILEINDEX_][ResourceString__FILEINDEX_];
};

struct  ResourceObject__FILEINDEX_ ro__FILEINDEX_;

void Resource__FILEINDEX__Object_Config() {
      
   ro__FILEINDEX_.active      = _ACTIVE_;
   ro__FILEINDEX_.object      = _OBJECT_;
   ro__FILEINDEX_.instances   = _INSTANCES_;
   
   memcpy(ro__FILEINDEX_.resources, (int[])  {
      _RESOURCELIST_
   }, sizeof ro__FILEINDEX_.resources);
   
   memcpy(ro__FILEINDEX_.type, (char[])  {
      _TYPELIST_
   }, sizeof ro__FILEINDEX_.type);

   char vl[ResourceLength__FILEINDEX_][ResourceString__FILEINDEX_] = {
      _VALUELIST_      
   };
   
   for (int i=0; i < ResourceLength__FILEINDEX_; i++) {
      strcpy(ro__FILEINDEX_.value[i], vl[i]);
   };
   
}

