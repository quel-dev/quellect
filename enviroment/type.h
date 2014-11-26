#include <map>
#include <vector>
#include <string>

#include "../node.h"

#define FUNCTION 0
#define INT 1
#define DOUBLE 2
#define STRING 3

class Enviroment;

class Value {
  public:
  int type;
  Value(int type):type(type){};
  Value(){}
};

class Int : public Value {
  int data;
  public:
  Int(int data):data(data){};
  int get_value(void);
};

class Double : public Value {
  double data;
  public:
  Double(int data):data(data){};
  double get_value(void);
};

class String : public Value {
  std::string data;
  public:
  String(std::string data):data(data){};
  std::string get_value(void);
};

class Function : public Value {
  std::vector<std::string> params_name;
  Node *literal;
  Enviroment *context;
  public: 
  Function(std::vector<std::string> params_name, Node* literal, Enviroment* context):
    params_name(params_name), literal(literal), context(context) {}
  Value* apply(const std::vector<Value*>&);
};

typedef std::map<std::string, Value> Symbol_hash_t;

