#include <cstdio>
#include <vector>

#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_
#include "environment.h"
#endif

Value CalcBinaryOp(const std::string& op_type,
                   Value operand1, Value operand2); 

bool CheckParamsMatched(Function* func, const std::vector<Value>& values, Environment* env = NULL);

Function* SelectFunction(const std::string& func_iden, const std::vector<Value>& values);
