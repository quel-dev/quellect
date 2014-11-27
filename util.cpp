#include "util.h"

Value CalcBinaryOp(const std::string& op_type,
                   Value operand1, Value operand2) {
  Value res;
  if (operand1.value_type_ == operand2.value_type_) {
    res.value_type_ = operand1.value_type_;
    if (op_type == "+") {
      switch(res.value_type_) {
        case INT_TYPE:
          res.int_ = operand1.int_ + operand2.int_;
        break;
        case DOUBLE_TYPE:
          res.double_ = operand1.double_ + operand2.double_;
        break;
      } 
    }
  } else {
    // TODO type conversion
  }
  return res;
}
