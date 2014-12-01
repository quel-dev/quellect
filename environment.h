#include <string>
#include <map>

enum {
  INT_TYPE, DOUBLE_TYPE
};

struct Value {
  Value():value_type_(-1){}
  Value(int data):value_type_(INT_TYPE) { int_ = data; }
  Value(double data):value_type_(DOUBLE_TYPE) { double_ = data; }
  union {
    int int_;   // -> int* int_;
    double double_; // -> double* double;
    //string* string_;
    //Function* function_;
    //NewType* newtype_;
    //Array* array_;
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
