#include <map>
#include <string>

#define FUNCTION 0
#define INT 1
#define DOUBLE 2
#define STRING 3

class Enviroment;

struct Value {
  void *data; Enviroment *context;
  int type;
};

typedef std::map<std::string, Value> Symbol_hash_t;

