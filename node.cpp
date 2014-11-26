#include "node.h"

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

AssignExpNode::AssignExpNode(Node *iden, Node* value):
    iden_(iden), value_(value) {
  node_type_ = "assign-exp";
}

BinaryOpExpNode::BinaryOpExpNode(
    Node* operand1, Node* operand2, const std::string& type) {
  operand1_ = operand1;
  operand2_ = operand2;
  node_type_ = type;   
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

NewTypeExpNode::NewTypeExpNode(const std::string& cons_iden, Node* exp_list):
    cons_iden_(cons_iden) {
  node_type_ = "newtype-exp";
  exp_list->CopyList(&exp_list_);
}

FuncLiteral::FuncLiteral(Node* parameters, Node* statements):
    parameters_(parameters), statements_(statements) {}

FuncDef::FuncDef(const std::string& func_iden, Node* func_literal):
    func_iden_(func_iden), func_literal_(func_literal) {
  node_type_ = "func_definition";
}

FuncExp::FuncExp(const std::string& func_iden, Node* parameters):
    func_iden_(func_iden), parameters_(parameters){
  node_type_ = "func_expression";    
  anonymous = false;
}

FuncExp::FuncExp(Node* func_literal, Node* parameters):
    func_literal_(func_literal), parameters_(parameters){
  node_type_ = "func_expression";    
  anonymous = true;
}

TypeIdenPair::TypeIdenPair(Node* type, const std::string& iden):
    iden_(iden), type_(type){
  node_type_ = "type_iden_pair";    
}

const std::string& TypeIdenPair::GetPairIden() {
  return iden_;
}

Node* TypeIdenPair::GetPairType() {
  return type_;
}

VarDef::VarDef(const std::string& var_iden, Node* initializer):
    var_iden_(var_iden), initializer_(initializer) {
  node_type_ = "var_def";
}

VarDef::VarDef(Node* pair, Node* initializer):
    var_iden_(pair->GetPairIden()), initializer_(initializer) {
  type_ = pair->GetPairType();
  node_type_ = "var_def";
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

int IntToken::GetIntTok() {
  return value_;
}

DoubleToken::DoubleToken(int token_id, double value):
    token_id_(token_id), value_(value){
  node_type_ = "double_token";    
}

double DoubleToken::GetDoubleTok() {
  return value_;
}

StringToken::StringToken(int token_id, const std::string& value):
    token_id_(token_id), value_(value){
  node_type_ = "double_token";    
}

const std::string& StringToken::GetStrTok() {
  return value_;
}
