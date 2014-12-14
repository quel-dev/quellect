#include <cstdio>
#include <vector>

#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_
#include "environment.h"
#endif

#ifndef TYPE_H_
#define TYPE_H_
#include "type.h"
#endif

#ifndef NODE_H_
#define NODE_H_
#include "node.h"
#endif

Value CalcBinaryOp(const std::string& op_type,
                   Value operand1, Value operand2); 

bool IsParamListMatched(std::vector<TypePattern*> pattern_list, const std::vector<Value>& values);

bool IsParamMatched(const TypePattern* pattern, Value value);

void BindParams(const std::vector<TypePattern*>& pattern, const std::vector<Value>& params, Environment* env);
