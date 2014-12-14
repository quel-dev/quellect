#ifndef NODE_H_
#define NODE_H_
#include "node.h"
#endif

#ifndef UTIL_H_
#define UTIL_H_
#include "util.h"
#endif

#define ANONY_IDEN "/"

const std::string& Node::GetType(){
  return node_type_;
}

ListNode::ListNode(const std::string& type, Node* item) {
  node_type_ = type;
  nodes_.push_back(item);
}

ListNode::ListNode(const std::string& type) {
  node_type_ = type;
}

void ListNode::Add(Node* node) {
  nodes_.push_back(node);
}

void ListNode::CopyList(std::vector<Node*>* nodes) {
  if (nodes != NULL) {
    nodes->clear();
    nodes->insert(nodes->begin(), nodes_.begin(), nodes_.end());
  } else {
    // print error log
  }
}

Value ListNode::Eval(Environment* env) {
  //puts(node_type_.c_str());
  if (node_type_ == "statement_list") {
    Value val;
    for (int i = 0 ; i < nodes_.size() ; ++i) {
      val = nodes_[i]->Eval(env);
    }
    return val;
  }
}

ValuePtrList ListNode::EvalToList(Environment* env) {
  if (node_type_ == "statement_list" || node_type_ == "exp_list") {
    ValuePtrList ret;
    for (int i = 0 ; i < nodes_.size() ; ++i) {
      ret.push_back(nodes_[i]->Eval(env));
    }
    return ret;
  }
}

BinaryOpExpNode::BinaryOpExpNode(
    Node* operand1, Node* operand2, const std::string& type) {
  operand1_ = operand1;
  operand2_ = operand2;
  node_type_ = type;   
}

Value BinaryOpExpNode::Eval(Environment* env) {
  //puts(node_type_.c_str());
  if (node_type_ == "=") {
    Value val = operand2_->Eval(env);
    //printf("assign iden: %s\n", operand1_->GetStrTok().c_str());
    env->set(operand1_->GetStrTok(), val);
    return val;
  } else {
    Value val1 = operand1_->Eval(env); 
    Value val2 = operand2_->Eval(env); 
    return CalcBinaryOp(node_type_, val1, val2);
  }
}

UnaryOpExpNode::UnaryOpExpNode(
    Node* operand, const std::string& type) {
  operand_ = operand;
  node_type_ = type;
}

PropertyIndexNode::PropertyIndexNode(Node* obj, Node* index):
    obj_(obj), index_(index){
  node_type_ = "property-index";   
}

AliasNode::AliasNode(const std::string& iden, Node* type):
    iden_(iden), type_(type){}

TypeDefNode::TypeDefNode(const std::string& iden, Node* cons):
    iden_(iden){
  node_type_ = "type-definition";    
  cons_list_.push_back(cons);
}

void TypeDefNode::Add(Node* cons) {
  cons_list_.push_back(cons);
}

ConsDefNode::ConsDefNode(const std::string& iden, Node* type_list):
    iden_(iden){
  type_list->CopyList(&type_list_);
}

FuncDef::FuncDef(const std::string& func_iden, TypePattern* parameters, Node* literal):
    func_iden_(func_iden), parameters_(parameters), literal_(literal) {
  node_type_ = "func_definition";
}

FuncExp::FuncExp(const std::string& func_iden, Node* parameters):
    func_iden_(func_iden), parameters_(parameters){
  node_type_ = "func_expression";
}

IfNode::IfNode(Node* condition, Node* if_branch, Node* else_branch):
    condition_(condition), if_branch_(if_branch), else_branch_(else_branch) {}

SwitchNode::SwitchNode(Node* var, Node* branches):
    var_(var), branches_(branches){}

void SwitchBranch::AddBranch(Node* condition, Node* action) {
  branches_.push_back(std::make_pair(condition, action));
}

JumpNode::JumpNode(const std::string& type, Node* value):
    value_(value){
  node_type_ = type;
}

BehaviorNode::BehaviorNode(const std::string& behav_iden, Node* signal):
    behav_iden_(behav_iden), signal_(signal){
  node_type_ = "behavior";    
}

EventNode::EventNode(Node* exp, Node* action):
    exp_(exp), action_(action){
  node_type_ = "event";    
}

IntToken::IntToken(int token_id, int value):
    token_id_(token_id), value_(value){
  node_type_ = "int_token";    
}

Value IntToken::Eval(Environment* env) {
  //puts(node_type_.c_str());
  //printf("%d\n", value_);
  return Value(value_);
}

DoubleToken::DoubleToken(int token_id, double value):
    token_id_(token_id), value_(value){
  node_type_ = "double_token";    
}

Value DoubleToken::Eval(Environment* env) {
  //puts(node_type_.c_str());
  //printf("%lf\n", value_);
  return Value(value_);
}

StringToken::StringToken(int token_id, const std::string& value):
    token_id_(token_id), value_(value){
  node_type_ = "string_token";    
}

const std::string& StringToken::GetStrTok() {
  return value_;
}

Value StringToken::Eval(Environment* env) {
  //puts(node_type_.c_str());
  //printf("%s\n",value_.c_str());
  if(env->ContainsVar(value_)) {
    return env->get(value_);
  } else {
    //fprintf(stderr, "undefined variable: %s\n", value_.c_str());
  }
}

Value TypeDefNode::Eval(Environment* env) {
  if (env->ContainsType(iden_)) {
    fprintf(stderr, "Redefined type %s\n", iden_.c_str());
  }
  std::vector<std::string> now;
  for (size_t i = 0; i < cons_list_.size(); i++) {
    cons_list_[i]->Eval(env);
    now.push_back(cons_list_[i]->GetStrTok());
    env->SetConsOfType(cons_list_[i]->GetStrTok(), iden_);
  }
  env->SetType(iden_, now);
  return Value(-1);
}

Value ConsDefNode::Eval(Environment* env) {
  if (env->ContainsCons(iden_)) {
    fprintf(stderr, "Redefined constructor %s\n", iden_.c_str());
  }
  std::vector<std::string> now;
  for (size_t i = 0; i < type_list_.size(); i++) {
    now.push_back(type_list_[i]->GetStrTok());
  }
  env->SetCons(iden_, now);
  return Value(-1);
}

Value FuncDef::Eval(Environment* env) {
  Function func;
#ifdef DEBUG
  printf("@%s\n", func_iden_.c_str());
  env->Display();
#endif
  func.context = new Environment;
  *(func.context) = *env;
  func.literal = literal_;
  func.param_list = parameters_;
  Value value(func);
  if (func_iden_ != ANONY_IDEN) {
    env->SetFunction(func_iden_, value);
  }
  return value;
}

Value FuncExp::Eval(Environment* env) {
  ValuePtrList params = parameters_->EvalToList(env);

  // For a constructor
  if (env->ContainsCons(func_iden_)) {
    std::vector<std::string> cons_type = env->GetCons(func_iden_);

    if (cons_type.size() != params.size()) {
      fprintf(stderr, "Incorrect number of parameters for constructor %s\n", func_iden_.c_str());
      return Value(-1);
    }

    for (size_t i = 0; i < params.size(); i++) {
      if (env->GetTypeByCons(params[i]->GetConsName()) != cons_type[i]) {
        fprintf(stderr, "Unmatched parameters for constructor %s\n", func_iden_.c_str());
        return Value(-1);
      }
    }
    Object now(func_iden_, params);
    Value tmp(now);
    return tmp;
  } else {
    Value *f = env->SelectFunction(func_iden_, params);
#ifdef DEBUG
    printf("@eval %s\n", func_iden_.c_str());
    f->function_->context->Display();
#endif
    Environment* new_env = new Environment(f->function_->context);
    BindParams(f->function_->param_list->sub_types, params, new_env);
#ifdef DEBUG
    printf("@new_env %s\n", func_iden_.c_str());
    new_env->Display();
#endif
    return f->function_->literal->Eval(new_env);
  }
}

