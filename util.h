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

bool compatibleForArith(const Value&, const Value&);

Value CalcBinaryOp(const std::string& op_type,
                   const Value& operand1, const Value& operand2); 

bool IsEqual(const Value&, const Value&);

bool IsParamListMatched(std::vector<TypePattern*> pattern_list, const ValuePtrList& values);

bool IsParamMatched(const TypePattern* pattern, const Value* value);

void BindParams(const std::vector<TypePattern*>& pattern, const ValuePtrList& params, Environment* env);

bool IsTrue(const Value&);
