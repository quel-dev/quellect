#include "type.h"

int Int::get_value(void) {return this->data;}
double Double::get_value(void) {return this->data;}
std::string String::get_value(void) {return this->data;}

Value* Function::apply(const std::vector<Value*> &params) {
  if (params.length() != params_name.length()) {
    // throw an exception
  }
  Enviroment *cur_env = new Enviroment;
  cur_env.set_father(this->context);
  for (size_t i = 0; i < params.length(); i++) {
    cur_env.set(params_name[i], params[i]);
  }
  Value *ret = this->literal->eval(cur_env);
  return ret;
}

