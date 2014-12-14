#ifndef UTIL_H_
#define UTIL_H_
#include "util.h"
#endif

struct TypePattern;
Value CalcBinaryOp(const std::string& op_type,
                   Value operand1, Value operand2) {
  if (operand1.value_type_ == operand2.value_type_) {
    int value_type_ = operand1.value_type_;
    if (op_type == "+") {
      switch(value_type_) {
        case INT_TYPE:
          return Value(*operand1.int_ + *operand2.int_);
        break;
        case DOUBLE_TYPE:
          return Value(*operand1.double_ + *operand2.double_);
        case STRING_TYPE:
          return Value(*operand1.string_ + *operand2.string_);
        break;
      } 
    }
   else if (op_type == "-") {
      switch(value_type_) {
        case INT_TYPE:
          return Value(*operand1.int_ - *operand2.int_);
        break;
        case DOUBLE_TYPE:
          return Value(*operand1.double_ - *operand2.double_);
        break;
        case STRING_TYPE:
          return Value(*operand1.string_ + *operand2.string_);
        break;
      } 
    }
  } else {
    // type conversion
  }
}

bool IsParamListMatched(std::vector<TypePattern*> pattern_list, const std::vector<Value>& values) {
  if (pattern_list.size() != values.size()) {
    return false;
  }
  for (size_t i = 0; i < values.size(); ++i) {
    if (!IsParamMatched(pattern_list[i], values[i])) return false;
  }
  return true;
}

bool IsParamMatched(const TypePattern *pattern, Value value) {
  if (value.IsPrimaryType()) {
    return pattern->IsTerminal();
  }
  if (value.GetConsName() != pattern->cons_name) {
    return false;
  }
  return IsParamListMatched(pattern->sub_types, value.GetValues());
}

void BindParams(const std::vector<TypePattern*>& pattern, const std::vector<Value>& params, Environment* env) {
  if (pattern.size() != params.size()) {
    // TODO
    fprintf(stderr, "unmatched parameters\n");
    return;
  }
  for (size_t i = 0; i < pattern.size(); ++i) {
    if (pattern[i]->IsTerminal()) {
      env->set(pattern[i]->GetConsName(), params[i]);
    } else {
      if (!params[i].IsPrimaryType() && params[i].GetConsName() == pattern[i]->GetConsName()) {
        BindParams(pattern[i]->sub_types, params[i].object_->values, env);
      } else {
        // TODO
        fprintf(stderr, "unmatched parameters\n");
      }
    }
  }
}

