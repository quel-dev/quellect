#include <string>
#include <vector>

class Node {
 public:
  Node(){};
  const std::string& GetType();
  virtual void Add(Node* item){}
  virtual void CopyList(std::vector<Node*>* items){}
  virtual const std::string& GetPairIden(){}
  virtual Node* GetPairType(){}
  virtual int GetIntTok(){}
  virtual double GetDoubleTok(){}
  virtual const std::string& GetStrTok(){}
  virtual void AddBranch(Node* condition, Node* action){}
 protected:
  std::string node_type_;
};

class ListNode : public Node {
 public:
  ListNode(const std::string& type, Node* item);
  ListNode(const std::string& type);
  void Add(Node* node);
  // copy nodes_ to nodes
  void CopyList(std::vector<Node*>* nodes);
 protected:
  std::vector<Node*> nodes_;
};

// e.g. a or a = b = c
class AssignExpNode : public Node {
 public:
  AssignExpNode(Node *iden, Node* value);
 protected:
  Node* iden_;
  Node* value_;
};

// e.g. a + b
class BinaryOpExpNode : public Node {
 public:
  BinaryOpExpNode(Node *operand1, Node* operand2, const std::string& type);
 protected:
  Node* operand1_;
  Node* operand2_;
};

// e.g. !pred
class UnaryOpExpNode : public Node {
 public:
  UnaryOpExpNode(Node *operand, const std::string& type);
 protected:
  Node* operand_;
};

// e.g. a[1234] obj["name"]
class PropertyIndexNode : public Node {
 public:
  PropertyIndexNode(Node *obj, Node *index);
 protected:
  Node* obj_;
  Node* index_;
};

class AliasNode : public Node {
 public:
  AliasNode(const std::string& iden, Node* type);
 protected:
  const std::string iden_;
  Node* type_;
};

class TypeDefNode : public Node {
 public:
  TypeDefNode(const std::string& iden, Node* cons);
  void Add(Node* cons);
 protected:
  const std::string iden_;
  std::vector<Node*> cons_list_;
};

class ConsDefNode : public Node {
 public:
  ConsDefNode(const std::string& iden, Node* type_list);
 protected:
  const std::string iden_;
  std::vector<Node*> type_list_;
};

class NewTypeExpNode : public Node {
 public:
  NewTypeExpNode(const std::string& cons_iden, Node* exp_list);
 protected:
  const std::string cons_iden_;
  std::vector<Node*> exp_list_;
};

class FuncLiteral : public Node {
 public:
  FuncLiteral(Node* parameters, Node* statements); 
 protected:
  Node* parameters_;
  Node* statements_;
};

class FuncDef : public Node {
 public:
  FuncDef(const std::string& func_iden, Node* func_literal);
 protected:
  const std::string func_iden_;
  Node* func_literal_;
};

class FuncExp : public Node {
 public:
  FuncExp(const std::string& func_iden, Node* parameters);
  FuncExp(Node* func_literal, Node* parameters);
 protected:
  bool anonymous;
  const std::string func_iden_;
  Node* func_literal_;
  Node* parameters_;
};

class TypeIdenPair : public Node {
 public:
  TypeIdenPair(Node* type, const std::string& iden);
  const std::string& GetPairIden();
  Node* GetPairType();
 protected:
  const std::string iden_;
  Node* type_;
};

class VarDef : public Node {
 public:
  VarDef(const std::string& var_iden, Node* initializer);
  VarDef(Node* pair, Node* initializer);
 protected:
  const std::string var_iden_;
  Node* type_;
  Node* initializer_;
};

class IfNode : public Node {
 public:
  IfNode(Node* condition, Node* if_branch, Node* else_branch);
 protected:
  Node* condition_;
  Node* if_branch_;
  Node* else_branch_;
};

class SwitchNode : public Node {
 public:
  SwitchNode(Node* var, Node* branches);
 protected:
  Node* var_;
  Node* branches_;
};

class SwitchBranch : public Node {
 public:
  SwitchBranch(){};
  void AddBranch(Node* condition, Node* action);
 protected:
  std::vector<std::pair<Node*, Node*> > branches_;
};

class JumpNode : public Node {
 public:
  JumpNode(const std::string& type, Node* value);
 protected:
  Node* value_;
};

class BehaviorNode : public Node {
 public:
  BehaviorNode(const std::string& behav_iden, Node* signal);
 protected:
  const std::string behav_iden_;
  Node* signal_;
};

class EventNode : public Node {
 public:
  EventNode(Node* exp, Node* action);
 protected:
  Node* exp_;
  Node* action_;
};

class IntToken : public Node {
 public:
  IntToken(int token_id, int value);
  int GetIntTok();
 protected:
  int token_id_;
  int value_;
};

class DoubleToken : public Node {
 public:
  DoubleToken(int token_id, double value);
  double GetDoubleTok();
 protected:
  int token_id_;
  double value_;
};

class StringToken : public Node {
 public:
  StringToken(int token_id, const std::string& value);
  const std::string& GetStrTok();
 protected:
  int token_id_;
  const std::string value_;
};

// TODO(tianshi) to combine Get*Tok
