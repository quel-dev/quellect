#include <cstdio>

#include <string>
#include <vector>

#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_
#include "environment.h"
#endif

#ifndef TYPE_H_
#define TYPE_H_
#include "type.h"
#endif

class Node {
 public:
  Node(){};
  const std::string& GetType();
  virtual void Add(Node* item){}
  virtual void CopyList(std::vector<Node*>* items){}
  virtual const std::string& GetPairIden(){}
  virtual Node* GetPairType(){}
  virtual const std::string& GetStrTok(){}
  virtual void AddBranch(Node* condition, Node* action){}
  virtual Value Eval(Environment* environment){puts(node_type_.c_str());};
  virtual std::vector<Value> EvalToList(Environment*){};
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
  Value Eval(Environment* env);
  std::vector<Value> EvalToList(Environment* env);
 protected:
  std::vector<Node*> nodes_;
};

// e.g. a + b
class BinaryOpExpNode : public Node {
 public:
  BinaryOpExpNode(Node *operand1, Node* operand2, const std::string& type);
  Value Eval(Environment* env);
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
  Value Eval(Environment *env);
  const std::string& GetStrTok(){return iden_;}
 protected:
  const std::string iden_;
  std::vector<Node*> cons_list_;
};

class ConsDefNode : public Node {
 public:
  ConsDefNode(const std::string& iden, Node* type_list);
  const std::string& GetStrTok(){return iden_;}
  Value Eval(Environment *env);
 protected:
  const std::string iden_;
  std::vector<Node*> type_list_;
};

struct TypePattern {
  std::string cons_name;
  std::vector<TypePattern*> sub_types;

  TypePattern(std::string cons_name):cons_name(cons_name){}
  void Add(TypePattern* oth) {sub_types.push_back(oth);}
  void SetConsName(std::string name) {cons_name = name;}
  bool IsTerminal(void) const {return sub_types.empty();}

  const std::string& GetConsName(void) {return cons_name;}

  void Display(void) {
    if (cons_name != "") {
      printf("%s", cons_name.c_str());
      if (this->IsTerminal()) return;
      else printf("::<");
    }
    for (size_t i = 0; i < sub_types.size(); ++i) {
      sub_types[i]->Display();
      if (i != sub_types.size() - 1) printf(", ");
    }
    if (cons_name != "") {
      printf(">");
    } else printf("\n");
  }
};

class FuncDef : public Node {
 public:
  FuncDef(const std::string& func_iden, TypePattern* parameters, Node* statements);
  Value Eval(Environment* env);
 protected:
  const std::string func_iden_;
  TypePattern* parameters_;
  Node* literal_;
};

class FuncExp : public Node {
 public:
  FuncExp(const std::string& func_iden, Node* parameters);
  Value Eval(Environment* env);
 protected:
  const std::string func_iden_;
  Node* parameters_;
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
  Value Eval(Environment* env);
 protected:
  int token_id_;
  int value_;
};

class DoubleToken : public Node {
 public:
  DoubleToken(int token_id, double value);
  Value Eval(Environment* env);
 protected:
  int token_id_;
  double value_;
};

class StringToken : public Node {
 public:
  StringToken(int token_id, const std::string& value);
  const std::string& GetStrTok();
  Value Eval(Environment* env);
 protected:
  int token_id_;
  const std::string value_;
};

// TODO(tianshi) to combine Get*Tok
