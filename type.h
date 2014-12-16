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

  int GetType(void) const {return value_type_;}

  int GetInt(void) const { return *int_; }
  double GetDouble(void) const { return *double_; }
  const std::string& GetString(void) const { return *string_; }
  const Function& GetFunction(void) const { return *function_; }
  const Object& GetObject(void) const { return *object_; }

  bool IsInt(void) const { return value_type_ == INT_TYPE; }
  bool IsDouble(void) const { return value_type_ == DOUBLE_TYPE; }
  bool IsString(void) const { return value_type_ == STRING_TYPE; }
  bool IsObject(void) const { return value_type_ == OBJECT_TYPE; }
  bool IsFunction(void) const { return value_type_ == FUNCTION_TYPE; }

  bool IsNumType(void) const { return IsInt() || IsDouble(); }
  bool IsPrimaryType(void) const;

  std::string GetConsName(void) const ;
  const ValuePtrList& GetValues(void) const;

  void Display() const;
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

  Value* push_back(Value *ptr) {
    _values.push_back(ptr);
    return ptr;
  }
  Value* push_back(const Value& v) {
    Value *ptr = new Value(v);
    _values.push_back(ptr);
    return ptr;
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

