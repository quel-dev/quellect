#include "util.h"

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

bool CheckParamsMatched(Function* func, const std::vector<Value> values, Environment* env = NULL) {
  return true;
}

Function* SelectFunction(const std::string& func_iden, const std::vector<Value>& values) {
  return NULL;
}

