#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_
#include "environment.h"
#endif

class Environment;
class Node;
struct TypePattern;
struct Object;
struct Function;
class ValuePtrList;

enum {
  INT_TYPE, DOUBLE_TYPE, STRING_TYPE, ARRAY_TYPE, FUNCTION_TYPE, OBJECT_TYPE
};

struct Value {
  Value():value_type_(-1){}
  Value(const Value& value);
  Value& operator =(const Value& value);

  Value(int data);
  Value(double data);
  Value(const std::string& data);
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

  void Display() const;

  bool IsPrimaryType(void) const;
  bool IsFunction(void) const {
    return value_type_ == FUNCTION_TYPE;
  }

  std::string GetConsName(void) const ;
  const ValuePtrList& GetValues(void) const;

};

class ValuePtrList {
  private:
  std::vector<Value*> _values;

  public:
  ValuePtrList() {}
  ValuePtrList(const ValuePtrList& oth) {
    for (size_t i = 0; i < oth._values.size(); i++) {
      Value *ptr = new Value(oth.GetRef(i));
      _values.push_back(ptr);
    }
  }

  ValuePtrList& operator =(const ValuePtrList& oth) {
    for (size_t i = 0; i < oth._values.size(); i++) {
      Value *ptr = new Value(oth.GetRef(i));
      _values.push_back(ptr);
    }
  }

  void push_back(Value *ptr) {
    _values.push_back(ptr);
  }
  void push_back(const Value& v) {
    Value *ptr = new Value(v);
    _values.push_back(ptr);
  }

  size_t size(void) const { return _values.size(); }
  
  Value* operator [](const int& index) const { return _values[index]; }
  
  const Value& GetRef(const int& index) const { return *_values[index]; }

  bool empty(void) const { return _values.empty(); }
};

struct Function {
  TypePattern* param_list;
  Node* literal;
  Environment* context;

  Function(TypePattern* param_list, Node* literal, Environment* context):param_list(param_list), literal(literal), context(context){};
  Function(){}

  Function(const Function&);
};

struct Object {
  std::string cons_name;
  ValuePtrList values;

  Object(std::string cons_name, const ValuePtrList& values):cons_name(cons_name), values(values) {}
  Object(){}

  void Add(const Value& value) {
    Value* v_ptr = new Value(value);
    values.push_back(v_ptr);
  }
};

