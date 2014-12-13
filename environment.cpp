#include <cstdio>

#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_
#include "environment.h"
#endif

void Environment::set(const std::string& iden, const Value& value) {
  if(variable_table_.find(iden) != variable_table_.end()) {
    // TODO: add to a variety of tables...
    variable_table_[iden] = value;
  } else {
    // TODO: change the value of a variable could lead to more reaction
    variable_table_[iden] = value;
  }
}

Value Environment::get(const std::string& iden) {
  if (ContainsVar(iden)) {
    return variable_table_[iden]; 
  } else {
    // TODO
    fprintf(stderr, "undefined variable: %s\n", iden.c_str());
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

