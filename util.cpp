#ifndef UTIL_H_
#define UTIL_H_
#include "util.h"
#endif

#include <cstdlib>
#include <cassert>

struct TypePattern;

void format_print(const char* operation_type, const char* operand_consname) {
  fprintf(stderr, "can not apply %s operation to %s variables\n",
      operation_type, operand_consname);
}

bool IsEqual(const Value& op1, const Value& op2) {
  assert(op1.GetType() == op2.GetType());
  int cur_type = op1.GetType();
  switch (cur_type) {
    case INT_TYPE:
      return op1.GetInt() == op2.GetInt();
    case DOUBLE_TYPE:
      return op1.GetDouble() == op2.GetDouble();
    case BOOL_TYPE:
      return op1.GetBool() == op2.GetBool();
    case STRING_TYPE:
      return op1.GetString() == op2.GetString();
    case OBJECT_TYPE:
      if (op1.GetConsName() == op2.GetConsName()) {
        const ValuePtrList& op1_value_list = op1.GetValues();
        const ValuePtrList& op2_value_list = op2.GetValues();
        if (op1_value_list.size() == op2_value_list.size()) {
          bool valid = true;
          for (size_t i = 0; i < op1_value_list.size(); i++) {
            if (!IsEqual(*op1_value_list[i], *op2_value_list[i])) {
              valid = false;
              break;
            }
          }
          if (valid) return true;
        }
      }
      return false;
    default:
      format_print("equal", "function");
      break;
  }
}

Value CalcBinaryOp(const std::string& op_type,
                   const Value& operand1, const Value& operand2) {
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
        default:
          format_print(op_type.c_str(), operand1.GetConsName().c_str());
          exit(-1);
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
        default:
          format_print(op_type.c_str(), operand1.GetConsName().c_str());
          exit(-1);
        break;
      } 
    } else if (op_type == "*") {
      switch(value_type_) {
        case INT_TYPE:
          return Value(*operand1.int_ * *operand2.int_);
        break;
        case DOUBLE_TYPE:
          return Value(*operand1.double_ * *operand2.double_);
        break;
        default:
          format_print(op_type.c_str(), operand1.GetConsName().c_str());
          exit(-1);
        break;
      }
    } else if (op_type == "/") {
      switch(value_type_) {
        case INT_TYPE:
          if (*operand2.int_ == 0) {
            fprintf(stderr, "divide by 0.\n"); 
            exit(-1);
          }
          return Value(*operand1.int_ / *operand2.int_);
        break;
        case DOUBLE_TYPE:
          return Value(*operand1.double_ / *operand2.double_);
        break;
        default:
          format_print(op_type.c_str(), operand1.GetConsName().c_str());
          exit(-1);
        break;
      }
    } else if (op_type == "%") {
      switch(value_type_) {
        case INT_TYPE:
          if (*operand2.int_ == 0) {
            fprintf(stderr, "divide by 0.\n"); 
            exit(-1);
          }
          return Value(*operand1.int_ % *operand2.int_);
        break;
        default:
          format_print(op_type.c_str(), operand1.GetConsName().c_str());
          exit(-1);
        break;
      }
    } else if (op_type == "<") {
      switch(value_type_) {
        case INT_TYPE:
          return Value(*operand1.int_ < *operand2.int_);
        break;
        case DOUBLE_TYPE:
          return Value(*operand1.double_ < *operand2.double_);
        break;
        case STRING_TYPE:
          return Value(*operand1.string_ < *operand2.string_);
        break;
        default:
          format_print(op_type.c_str(), operand1.GetConsName().c_str());
          exit(-1);
        break;
      }
    } else if (op_type == "<=") {
      switch(value_type_) {
        case INT_TYPE:
          return Value(*operand1.int_ <= *operand2.int_);
        break;
        case DOUBLE_TYPE:
          return Value(*operand1.double_ <= *operand2.double_);
        break;
        case STRING_TYPE:
          return Value(*operand1.string_ <= *operand2.string_);
        break;
        default:
          format_print(op_type.c_str(), operand1.GetConsName().c_str());
          exit(-1);
        break;
      }
    } else if (op_type == ">") {
      switch(value_type_) {
        case INT_TYPE:
          return Value(*operand1.int_ > *operand2.int_);
        break;
        case DOUBLE_TYPE:
          return Value(*operand1.double_ > *operand2.double_);
        break;
        case STRING_TYPE:
          return Value(*operand1.string_ > *operand2.string_);
        break;
        default:
          format_print(op_type.c_str(), operand1.GetConsName().c_str());
          exit(-1);
        break;
      }
    } else if (op_type == ">=") {
      switch(value_type_) {
        case INT_TYPE:
          return Value(*operand1.int_ >= *operand2.int_);
        break;
        case DOUBLE_TYPE:
          return Value(*operand1.double_ >= *operand2.double_);
        break;
        case STRING_TYPE:
          return Value(*operand1.string_ >= *operand2.string_);
        break;
        default:
          format_print(op_type.c_str(), operand1.GetConsName().c_str());
          exit(-1);
        break;
      }
    } else if (op_type == "==") {
      return Value(IsEqual(operand1, operand2));
    } else if (op_type == "!=") {
      return Value( ! IsEqual(operand1, operand2));
    } else if (op_type == "&&") {
      switch(value_type_) {
        case BOOL_TYPE:
            return Value(*operand1.bool_ && *operand2.bool_);
        break;
        default:
            format_print(op_type.c_str(), operand1.GetConsName().c_str());
            exit(-1);
        break;
      }
    } else if (op_type == "||") {
      switch(value_type_) {
        case BOOL_TYPE:
            return Value(*operand1.bool_ || *operand2.bool_);
        break;
        default:
            format_print(op_type.c_str(), operand1.GetConsName().c_str());
            exit(-1);
        break;
      }
    } else {
      fprintf(stderr, "undefined binary operator: %s\n", op_type.c_str());
      exit(-1);
    }
  } else {
    fprintf(stderr, "inconsistent type: op1:[%s], op2:[%s]\n",
        operand1.GetConsName().c_str(), operand2.GetConsName().c_str());
    exit(-1);
    // TODO type conversion
  }
}

bool IsParamListMatched(std::vector<TypePattern*> pattern_list, const ValuePtrList& values) {
  if (pattern_list.size() != values.size()) {
    return false;
  }

#ifdef DEBUG
  printf("@matching...\n");
  fflush(stdout);
#endif

  for (size_t i = 0; i < values.size(); ++i) {

#ifdef DEBUG
    printf("-");
    pattern_list[i]->Display(); puts("");
    printf("+");
    values[i]->Display(); puts("");
    fflush(stdout);
#endif

    if (!IsParamMatched(pattern_list[i], values[i])) return false;
  }
  return true;
}

bool IsParamMatched(const TypePattern *pattern, const Value* value) {
  // The terminal pattern can match anything
  if (pattern->IsTerminal()) return true;

  // The pattern must not be a terminal so the value shouldn't be atomic
  if (value->IsPrimaryType()) return false;

  if (value->GetConsName() != pattern->cons_name) {
    return false;
  }
  return IsParamListMatched(pattern->sub_types, value->GetValues());
}

void BindParams(const std::vector<TypePattern*>& pattern, const ValuePtrList& params, Environment* env) {
  if (pattern.size() != params.size()) {
    // TODO
    fprintf(stderr, "unmatched parameters\n");
    return;
  }
  for (size_t i = 0; i < pattern.size(); ++i) {
    if (pattern[i]->IsTerminal()) {
      env->set(pattern[i]->GetConsName(), *params[i]);
    } else {
      if (!params[i]->IsPrimaryType() && params[i]->GetConsName() == pattern[i]->GetConsName()) {
        BindParams(pattern[i]->sub_types, params[i]->object_->values, env);
      } else {
        // TODO
        fprintf(stderr, "unmatched parameters\n");
      }
    }
  }
}

bool IsTrue(const Value& value) {
  switch(value.GetType()) {
    case INT_TYPE:
      return value.GetInt() != 0;
    case DOUBLE_TYPE:
      return value.GetDouble() != 0;
    case STRING_TYPE:
      return value.GetString() != "";
    case BOOL_TYPE:
      return value.GetBool();
  }
  return true;
}

