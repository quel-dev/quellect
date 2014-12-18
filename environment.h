#include <string>
#include <map>
#include <vector>

#ifndef TYPE_H_
#define TYPE_H_
#include "type.h"
#endif

struct Value;
class ValuePtrList;

class Environment {
 public:
  void set(const std::string& iden, const Value& value);
  Value get(const std::string& iden);
  Value GetVariable(const std::string&);

  void SetType(const std::string& iden, const std::vector<std::string>& value);
  std::vector<std::string> GetType(const std::string& iden);
  bool ContainsType(const std::string& iden);

  void SetCons(const std::string& iden, const std::vector<std::string>& value);
  std::vector<std::string> GetCons(const std::string& iden);
  bool ContainsCons(const std::string& iden);

  void SetConsOfType(std::string cons_name, std::string type_name);
  std::string GetTypeByCons(std::string);

  Value* SetFunction(const std::string& iden, const Value& value);
  Value SelectFunction(const std::string& iden, const ValuePtrList& values) const; 
  Value GetFunction(const std::string& iden) const;

  Environment(Environment* env = NULL):father(env){}

  void Display(void);

 protected:
  std::map<std::string, Value> variable_table_;
  std::map<std::string, std::vector<std::string> > type_table_;
  std::map<std::string, std::vector<std::string> > cons_table_;
  std::map<std::string, std::string> cons_to_type_table_;
  std::map<std::string, ValuePtrList > functions_table_;

  Environment *father;
};

