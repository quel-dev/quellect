#ifndef TYPE_H_
#define TYPE_H_
#include "type.h"
#endif

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

const std::vector<Value>& Value::GetValues(void) {
  return object_->values;
}
