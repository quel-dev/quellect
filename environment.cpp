#include <cstdio>

#include "environment.h"

Value::Value(int data):value_type_(INT_TYPE) {
  int_ = new int;
  *int_ = data;
}

Value::Value(double data):value_type_(DOUBLE_TYPE) {
  double_ = new double;
  *double_ = data;
}

Value::Value(const std::string& data):value_type_(STRING_TYPE) {
  string_ = new std::string(data);
}

Value::Value(const Function& f):value_type_(FUNCTION_TYPE) {
  function_ = new Function;
  *function_ = f;
}

Value::Value(const Object& o):value_type_(OBJECT_TYPE) {
  object_ = new Object;
  *object_ = o;
}

Value::Value(const Value& v) {
  value_type_ = v.value_type_;
  switch (v.value_type_) {
    case INT_TYPE:
      int_ = new int;
      *int_ = *v.int_;
    break;
    case DOUBLE_TYPE:
      double_ = new double;
      *double_ = *v.double_;
    break;
    case STRING_TYPE:
      string_ = new std::string(*v.string_);
    break;
    case FUNCTION_TYPE:
      function_ = new Function;
      *function_ = *v.function_;
    case OBJECT_TYPE:
      object_ = new Object;
      *object_ = *v.object_;
  }
}

void Value::display() {
  switch (value_type_) {
    case INT_TYPE:
      printf("%d", *int_);
    break;
    case DOUBLE_TYPE:
      printf("%lf", *double_);
    break;
    case STRING_TYPE:
      printf("%s", string_->c_str());
    break;
    case FUNCTION_TYPE:
      printf("[Function]");
    break;
    case OBJECT_TYPE:
      if (object_->values.empty()) {
        printf("%s\n", object_->cons_name.c_str());
      } else {
        printf("%s::<", object_->cons_name.c_str());
        for (size_t i = 0; i < object_->values.size(); i++) {
          object_->values[i].display();
          if (i != object_->values.size() - 1) {
            printf(",");
          }
        }
        printf(">");
      }
    break;
  }
}

bool Value::IsPrimaryType(void) {
  return value_type_ != OBJECT_TYPE;
}

std::string Value::GetConsName(void) {
  if (IsPrimaryType()) {
    switch (value_type_) {
      case INT_TYPE:
        return "int";
      case DOUBLE_TYPE:
        return "double";
      case STRING_TYPE:
        return "string";
      case FUNCTION_TYPE:
        return "function";
    }
  } else {
    return object_->cons_name;
  }
}

void Environment::set(const std::string& iden, const Value& value) {
  if(variable_table_.find(iden) != variable_table_.end()) {
    // TODO: add to a variety of tables...
    variable_table_[iden] = value;
  } else {
    // TODO: change the value of a variable could lead to more reaction
    variable_table_[iden] = value;
  }
}

Value Environment::get(const std::string& iden) {
  if (ContainsVar(iden)) {
    return variable_table_[iden]; 
  } else {
    // TODO
    fprintf(stderr, "undefined variable: %s\n", iden.c_str());
  }
}

bool Environment::ContainsVar(const std::string& iden) {
  if (variable_table_.find(iden) == variable_table_.end()) {
    return false;
  } else {
    return true;
  }
}


void Environment::SetType(const std::string& iden, const std::vector<std::string>& value) {
  type_table_[iden] = value;
}

std::vector<std::string> Environment::GetType(const std::string& iden) {
  if (ContainsType(iden)) {
    return type_table_[iden]; 
  } else {
    // TODO
    fprintf(stderr, "undefined type: %s\n", iden.c_str());
  }
}

bool Environment::ContainsType(const std::string& iden) {
  if (type_table_.find(iden) == type_table_.end()) {
    return false;
  } else {
    return true;
  }
}

void Environment::SetCons(const std::string& iden, const std::vector<std::string>& value) {
  cons_table_[iden] = value;
}

std::vector<std::string> Environment::GetCons(const std::string& iden) {
  if (ContainsCons(iden)) {
    return cons_table_[iden];
  } else {
    // TODO
    fprintf(stderr, "undefined constructor: %s\n", iden.c_str());
  }
}

bool Environment::ContainsCons(const std::string& iden) {
  if (cons_table_.find(iden) == cons_table_.end()) {
    return false;
  } else {
    return true;
  }
}

std::string Environment::GetTypeByCons(std::string cons_name) {
  __typeof(cons_to_type_table_.begin()) it = cons_to_type_table_.find(cons_name);
  if (it == cons_to_type_table_.end()) {
    if (cons_name == "int" || cons_name == "double" || cons_name == "string" || cons_name == "function") {
      return cons_name;
    }
    // TODO
    fprintf(stderr, "can not find the type of constructor %s\n", cons_name.c_str());
  } else {
    return it->second;
  }
}

void Environment::SetConsOfType(std::string cons_name, std::string type_name) {
  cons_to_type_table_[cons_name] = type_name;
}

