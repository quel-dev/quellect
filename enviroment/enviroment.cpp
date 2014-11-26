#include "enviroment.h"

void Enviroment::set(std::string id, Value data) {
  symbols[id] = data;
}

Value Enviroment::get(std::string id) {
  Enviroment *ptr = this;
  while (ptr) {
    Symbol_hash_t::iterator it = ptr->symbols.find(id);
    if (it != symbols.end()) return it->second;
  }
  // throw an exception
}

void Enviroment::set_father(Enviroment* oth) {
  this->father = oth;
}

