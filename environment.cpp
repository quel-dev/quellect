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
  }
}

void Value::display() {
  //puts("display!");
  switch (value_type_) {
    case INT_TYPE:
      printf("%d\n", *int_);
    break;
    case DOUBLE_TYPE:
      printf("%lf\n", *double_);
    break;
    case STRING_TYPE:
      printf("%s\n", string_->c_str());
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
