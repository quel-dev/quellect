#ifndef TYPE_H_
#define TYPE_H_
#include "type.h"
#endif

#ifndef UTIL_H_
#define UTIL_H_
#include "util.h"
#endif

#include <cstdlib>
#include <cmath>

Value::Value(bool data):value_type_(BOOL_TYPE) {
  bool_ = new bool;
  *bool_ = data;
}

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

bool Value::operator == (const Value& v) {
  if (value_type_ != v.value_type_) {
    return false;
  } else {
    switch (value_type_) {
      case BOOL_TYPE:
        return *bool_ == *v.bool_;
      case INT_TYPE:
        return *int_ == *v.int_;
      case DOUBLE_TYPE:
        return fabs(*double_ - *v.double_) < 1e-8;
      case STRING_TYPE:
        return *string_ == *v.string_;
      default:
        fprintf(stderr, "cannot judge equality: %s",
                v.GetConsName().c_str());
        exit(-1);
    }
  }
}

Value::Value(const Value& v) {
  value_type_ = v.value_type_;
  switch (v.value_type_) {
    case BOOL_TYPE:
      bool_ = new bool;
      *bool_ = *v.bool_;
    break;
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
      *function_ = *(v.function_);
    break;
    case OBJECT_TYPE:
      object_ = new Object;
      *object_ = *(v.object_);
    break;
  }
}

Value& Value::operator =(const Value& v) {
  value_type_ = v.value_type_;
  switch (v.value_type_) {
    case BOOL_TYPE:
      bool_ = new bool;
      *bool_ = *v.bool_;
    break;
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
      *function_ = *(v.function_);
    break;
    case OBJECT_TYPE:
      object_ = new Object;
      *object_ = *(v.object_);
    break;
  }
  return *this;
}

void Value::Display() const {
  switch (value_type_) {
    case BOOL_TYPE:
      if (*bool_) {
        printf("%s", "true");
      } else {
        printf("%s", "false");
      }
    break;
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
      printf("[Function], parameters: ");
      function_->param_list->Display();
    break;
    case OBJECT_TYPE:
      if (object_->values.empty()) {
        printf("%s\n", object_->cons_name.c_str());
      } else {
        printf("%s::<", object_->cons_name.c_str());
        for (size_t i = 0; i < object_->values.size(); i++) {
          object_->values[i]->Display();
          if (i != object_->values.size() - 1) {
            printf(",");
          }
        }
        printf(">");
      }
    break;
  }
}

bool Value::IsPrimaryType(void) const {
  return value_type_ != OBJECT_TYPE;
}

std::string Value::GetConsName(void) const {
  if (IsPrimaryType()) {
    switch (value_type_) {
      case BOOL_TYPE:
        return "bool";
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

const ValuePtrList& Value::GetValues(void) const {
  return object_->values;
}

Function::Function(const Function& oth) {
  param_list = new TypePattern(*(oth.param_list));
  literal = new Node;
  *literal = *(oth.literal);
  context = new Environment(oth.context);
}

