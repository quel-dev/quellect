#include <cstdio>

#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_
#include "environment.h"
#endif

#ifndef NODE_H_
#define NODE_H_
#include "node.h"
#endif

#ifndef UTIL_H_
#define UTIL_H_
#include "util.h"
#endif

void Environment::set(const std::string& iden, const Value& value) {
  if (value.IsFunction()) {
    // function should be saved to a separate symbol table
    SetFunction(iden, value);

  } else {
    if(variable_table_.find(iden) != variable_table_.end()) {
      // TODO: add to a variety of tables...
      variable_table_[iden] = value;
    } else {
      // TODO: change the value of a variable could lead to more reaction
      variable_table_[iden] = value;
    }
  }
}

Value Environment::get(const std::string& iden) {
  if (ContainsVar(iden)) {
    return variable_table_[iden]; 
  } else {
    if (father != NULL) {
      return father->get(iden);
    } else {
      // TODO
      fprintf(stderr, "undefined variable: %s\n", iden.c_str());
    }
  }
}

bool Environment::ContainsVar(const std::string& iden) {
  if (variable_table_.find(iden) == variable_table_.end()) {
    return false;
  } else {
    return true;
  }
}


void Environment::SetType(const std::string& iden, const std::vector<std::string>& value) {
  type_table_[iden] = value;
}

std::vector<std::string> Environment::GetType(const std::string& iden) {
  if (ContainsType(iden)) {
    return type_table_[iden]; 
  } else {
    // TODO
    fprintf(stderr, "undefined type: %s\n", iden.c_str());
  }
}

bool Environment::ContainsType(const std::string& iden) {
  if (type_table_.find(iden) == type_table_.end()) {
    return false;
  } else {
    return true;
  }
}

void Environment::SetCons(const std::string& iden, const std::vector<std::string>& value) {
  cons_table_[iden] = value;
}

std::vector<std::string> Environment::GetCons(const std::string& iden) {
  if (ContainsCons(iden)) {
    return cons_table_[iden];
  } else {
    // TODO
    fprintf(stderr, "undefined constructor: %s\n", iden.c_str());
  }
}

bool Environment::ContainsCons(const std::string& iden) {
  if (cons_table_.find(iden) == cons_table_.end()) {
    return false;
  } else {
    return true;
  }
}

std::string Environment::GetTypeByCons(std::string cons_name) {
  __typeof(cons_to_type_table_.begin()) it = cons_to_type_table_.find(cons_name);
  if (it == cons_to_type_table_.end()) {
    if (cons_name == "int" || cons_name == "double" || cons_name == "string" || cons_name == "function") {
      return cons_name;
    }
    // TODO
    fprintf(stderr, "can not find the type of constructor %s\n", cons_name.c_str());
  } else {
    return it->second;
  }
}

void Environment::SetConsOfType(std::string cons_name, std::string type_name) {
  cons_to_type_table_[cons_name] = type_name;
}

void Environment::SetFunction(const std::string& iden, const Value& value) {
  functions_table_[iden].push_back(value);
}

Value Environment::SelectFunction(const std::string& iden, const std::vector<Value>& values) {
  __typeof(functions_table_.begin()) it = functions_table_.find(iden);
  if (it == functions_table_.end()) {
    if (father != NULL) {
      return father->SelectFunction(iden, values);
    } else {
      // TODO
      fprintf(stderr, "can not find the function %s\n", iden.c_str());
    }
  }
  for (size_t i = 0; i < it->second.size(); ++i) {
    if (IsParamListMatched(it->second[i].function_->param_list->sub_types, values)) {
      return it->second[i];
    }
  }
  if (father != NULL) {
    return father->SelectFunction(iden, values);
  } else {
    // TODO
    fprintf(stderr, "can not find a matched function\n", iden.c_str());
  }
}

