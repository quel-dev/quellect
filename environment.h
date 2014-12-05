#include <string>
#include <map>

enum {
  INT_TYPE, DOUBLE_TYPE, STRING_TYPE, ARRAY_TYPE
};

/*
class Array {
 public:
  Value& operator[] (int index) {
    
  }
};
*/

struct Value {
  Value():value_type_(-1){}
  Value(int data);
  Value(double data);
  Value(const std::string& data);
  Value(const Value& value);
  union {
    int* int_;
    double* double_;
    std::string* string_;
    //Array* array_;
    //Function* function_;
    //NewType* newtype_;
  };
  int value_type_;
  void display();
};

class Environment {
 public:
  void set(const std::string& iden, const Value& value);
  Value get(const std::string& iden);
  bool ContainsVar(const std::string& iden);
 protected:
  std::map<std::string, Value> variable_table_;
};
