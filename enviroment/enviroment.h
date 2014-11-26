#include "type.h"

class Enviroment {
  Symbol_hash_t symbols;
  Enviroment *father;
  
  public:
  void set(std::string, Value);
  Value get(std::string);
  void set_father_of(Enviroment*);
};

