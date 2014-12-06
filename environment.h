#include <string>
#include <map>
#include <vector>

#include "type.h"

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
  void display();
  bool IsPrimaryType(void);
  std::string GetConsName(void);
};

class Environment {
 public:
  void set(const std::string& iden, const Value& value);
  Value get(const std::string& iden);
  bool ContainsVar(const std::string& iden);

  void SetType(const std::string& iden, const std::vector<std::string>& value);
  std::vector<std::string> GetType(const std::string& iden);
  bool ContainsType(const std::string& iden);

  void SetCons(const std::string& iden, const std::vector<std::string>& value);
  std::vector<std::string> GetCons(const std::string& iden);
  bool ContainsCons(const std::string& iden);

  void SetConsOfType(std::string cons_name, std::string type_name);
  std::string GetTypeByCons(std::string);

 protected:
  std::map<std::string, Value> variable_table_;
  std::map<std::string, std::vector<std::string> > type_table_;
  std::map<std::string, std::vector<std::string> > cons_table_;
  std::map<std::string, std::string> cons_to_type_table_;
};

