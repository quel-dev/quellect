#include <cstdio>

#include "environment.h"

void Value::display() {
  //puts("display!");
  switch (value_type_) {
    case INT_TYPE:
      printf("%d\n", int_);
    break;
    case DOUBLE_TYPE:
      printf("%lf\n", double_);
    break;
  }
}

void Environment::set(const std::string& iden, const Value& value) {
  if(variable_table_.find(iden) != variable_table_.end()) {
    variable_table_[iden] = value;
    // add to a variety of tables...
  } else {
    variable_table_[iden] = value;
    // change the value of a variable could lead to more reaction
  }
}

Value Environment::get(const std::string& iden) {
  if (ContainsVar(iden)) {
    return variable_table_[iden]; 
  } else {
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
