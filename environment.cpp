#include <cstdio>
#include <iostream>
#include <exception>
#include <set>

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

const std::map<std::string, Node*>& Environment::GetSig(const std::string& iden) {
  return signal_table_[iden];
}

void Environment::AddSignalAction (Node* signal, const std::string& behav_iden) {
    const std::set<std::string>& sig_idens =
        signal->GetSubtreeIden();
#define foreach(it, T) for(__typeof((T).begin()) it = (T).begin(); it != (T).end(); ++it)
    foreach(it, sig_idens) {
      if (ContainsSig(*it)) {
        std::map<std::string, Node*>& cur = signal_table_[*it];
        cur.insert(make_pair(behav_iden, signal));
      } else {
        std::map<std::string, Node*> tmp;
        tmp.insert(make_pair(behav_iden, signal));
        signal_table_.insert(make_pair(*it, tmp));
      }
    }
#undef foreach
}

void Environment::Display(void) {
#define foreach(it, T) for(__typeof((T).begin()) it = (T).begin(); it != (T).end(); ++it)
  printf("---variable_table---\n");
  foreach(it, variable_table_) {
    printf("Name: %s, Value: ", it->first.c_str());
    it->second.Display();
    puts("");
  }
  printf("---type_table---\n");
  foreach(it, type_table_) {
    printf("Name: %s, Cons: ", it->first.c_str());
    foreach(ot, it->second) {
      printf("%s ", ot->c_str());
    }
    puts("");
  }
  printf("---constructor_table---\n");
  foreach(it, cons_table_) {
    printf("Name: %s, Component: ", it->first.c_str());
    foreach(ot, it->second) {
      printf("%s ", ot->c_str());
    }
    puts("");
  }
  printf("---function_table---\n");
  foreach(it, functions_table_) {
    printf("Name: %s\n", it->first.c_str());
    for (size_t i = 0; i < it->second.size(); ++i) {
      printf("    "); it->second[i]->Display();
    }
  }
#undef foreach
}

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
  try {
    return GetVariable(iden);
  } catch (const std::exception& e) {
    return GetFunction(iden);
  }
}

Value Environment::GetVariable(const std::string& iden) {
  if (variable_table_.find(iden) != variable_table_.end()) {
    return variable_table_[iden];
  } else {
    if (father != NULL) {
      return father->GetVariable(iden);
    } else {
      throw std::exception();
    }
  }
}

void Environment::SetType(const std::string& iden, const std::vector<std::string>& value) {
  type_table_[iden] = value;
}

std::vector<std::string> Environment::GetType(const std::string& iden) {
  if (type_table_.find(iden) != type_table_.end()) {
    return type_table_[iden]; 
  } else {
    if (father != NULL) {
      return father->GetType(iden);
    } else {
      // TODO
      fprintf(stderr, "undefined type: %s\n", iden.c_str());
    }
  }
}

bool Environment::ContainsType(const std::string& iden) {
  if (type_table_.find(iden) != type_table_.end()) {
    return true;
  } else {
    if (father != NULL) {
      return father->ContainsType(iden);
    } else {
      return false;
    }
  }
}

bool Environment::ContainsSig(const std::string& iden) {
  if (signal_table_.find(iden) != signal_table_.end()) {
    return true;
  } else {
    if (father != NULL) {
      return father->ContainsSig(iden);
    } else {
      return false;
    }
  }
}

void Environment::SetCons(const std::string& iden, const std::vector<std::string>& value) {
  cons_table_[iden] = value;
}

std::vector<std::string> Environment::GetCons(const std::string& iden) {
  if (cons_table_.find(iden) != cons_table_.end()) {
    return cons_table_[iden];
  } else {
    if (father != NULL) {
      return father->GetCons(iden);
    } else {
      // TODO
      fprintf(stderr, "undefined constructor: %s\n", iden.c_str());
    }
  }
}

bool Environment::ContainsCons(const std::string& iden) {
  if (cons_table_.find(iden) != cons_table_.end()) {
    return true;
  } else {
    if (father != NULL) {
      return father->ContainsCons(iden);
    } else {
      return false;
    }
  }
}

std::string Environment::GetTypeByCons(std::string cons_name) {
  __typeof(cons_to_type_table_.begin()) it = cons_to_type_table_.find(cons_name);
  if (it == cons_to_type_table_.end()) {
    if (cons_name == "int" || cons_name == "double" || cons_name == "string" || cons_name == "function") {
      return cons_name;
    }
    if (father != NULL) {
      return father->GetTypeByCons(cons_name);
    } else {
      // TODO
      fprintf(stderr, "can not find the type of constructor %s\n", cons_name.c_str());
    }
  } else {
    return it->second;
  }
}

void Environment::SetConsOfType(std::string cons_name, std::string type_name) {
  cons_to_type_table_[cons_name] = type_name;
}

Value* Environment::SetFunction(const std::string& iden, const Value& value) {
  return functions_table_[iden].push_back(value);
}

Value Environment::SelectFunction(const std::string& iden, const ValuePtrList& values) const {
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
    if (IsParamListMatched(it->second[i]->function_->param_list->sub_types, values)) {
      return *(it->second[i]);
    }
  }
  if (father != NULL) {
    return father->SelectFunction(iden, values);
  } else {
    // TODO
    fprintf(stderr, "can not find a matched function %s\n", iden.c_str());
  }
}

Value Environment::GetFunction(const std::string& iden) const {
  __typeof(functions_table_.begin()) it = functions_table_.find(iden);
  if (it == functions_table_.end()) {
    if (father != NULL) {
      return father->GetFunction(iden);
    } else {
      // TODO
      fprintf(stderr, "can not find the function %s\n", iden.c_str());
    }
  } else {
    if (it->second.size() > 1) {
      // TODO
      fprintf(stderr, "there is multiple function instance %s\n", iden.c_str());
    } else {
      return *(it->second[0]);
    }
  }
}

