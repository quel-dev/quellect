class Environment;
class Node;
struct Value;

struct Function {
  Environment* context;
  Node* literal;
  Node* param_list;

  public:
  Function(Node* param_list, Node* literal, Environment* context):param_list(param_list), literal(literal), context(context){};
  Function(){}
};

struct Object {
  std::string cons_name;
  std::vector<Value> values;

  Object(std::string cons_name):cons_name(cons_name){}
  Object(){}

  void Add(const Value& value) {
    values.push_back(value);
  }
};

