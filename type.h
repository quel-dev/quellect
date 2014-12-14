#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_
#include "environment.h"
#endif

class Environment;
class Node;
struct TypePattern;
struct Object;
struct Function;

enum {
  INT_TYPE, DOUBLE_TYPE, STRING_TYPE, ARRAY_TYPE, FUNCTION_TYPE, OBJECT_TYPE
};

struct Value {
  Value():value_type_(-1){}
  Value(int data);
  Value(double data);
  Value(const std::string& data);
  Value(const Value& value);
  Value(const Function& f);
  Value(const Object& f);
  union {
    int* int_;
    double* double_;
    std::string* string_;
    Function* function_;
    Object* object_;
    // TODO
    //Array* array_;
    //NewType* newtype_;
  };
  int value_type_;

  void display() const;

  bool IsPrimaryType(void) const;
  bool IsFunction(void) const {
    return value_type_ == FUNCTION_TYPE;
  }

  std::string GetConsName(void) const ;
  const std::vector<Value>& GetValues(void) const;
};

struct Function {
  TypePattern* param_list;
  Node* literal;
  Environment* context;

  Function(TypePattern* param_list, Node* literal, Environment* context):param_list(param_list), literal(literal), context(context){};
  Function(){}
};

struct Object {
  std::string cons_name;
  std::vector<Value> values;

  Object(std::string cons_name, std::vector<Value> values):cons_name(cons_name), values(values){}
  Object(){}

  void Add(const Value& value) {
    values.push_back(value);
  }
};

