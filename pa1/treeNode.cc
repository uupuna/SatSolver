 #include "treeNode.h"
 #include<iostream>



TreeNode::TreeNode(std::string cntt): content (cntt) {}

std::string TreeNode::getContent() const {
  // your code starts here
  return content;
}

TreeNode *TreeNode::getLeftChild() const {
  // your code starts here
  return leftChild;
}
TreeNode *TreeNode::getRightChild() const {
  // your code starts here
  return rightChild;
}

void TreeNode::updateLeftChild(TreeNode *lChild) {
  // your code starts here
  if(lChild!=nullptr){
    leftChild=lChild;
  }
  else{
    throw("Error: invalid input");
  }
}

void TreeNode::updateChildren(TreeNode *lChild, TreeNode *rChild) {
  // your code starts here
  if(lChild!=nullptr&&rChild!=nullptr){
    leftChild=lChild;
    rightChild=rChild;
  }
  else{
    throw("Error: invalid input");
  }
}

OperatorNode::OperatorNode(std::string cntt): TreeNode(cntt) {}

bool OperatorNode::evaluate(const std::map<std::string, bool> &assignment) const {
  // your code starts here
  if(getContent()=="+"){
    TreeNode* leftChild=getLeftChild();
    TreeNode* rightChild=getRightChild();
    bool left_value = leftChild->evaluate(assignment);
    bool right_value = rightChild->evaluate(assignment);
    return (left_value||right_value);
  }
  else if(getContent()=="-"){
    TreeNode* leftChild=getLeftChild();
    bool left_value = leftChild->evaluate(assignment);
    if(left_value) return false;
    else return true;
  }
  else if(getContent()=="*"){
    TreeNode* leftChild=getLeftChild();
    TreeNode* rightChild=getRightChild();
    bool left_value = leftChild->evaluate(assignment);
    bool right_value = rightChild->evaluate(assignment);
    return (left_value&&right_value);
  }
  return true;
}

ConstantNode::ConstantNode(std::string cntt): TreeNode(cntt) {}

bool ConstantNode::evaluate(const std::map<std::string, bool> &assignment) const {
  // your code starts here
  if(getContent()=="0")
    return false;
  else
    return true;
}

VariableNode::VariableNode(std::string cntt): TreeNode(cntt) {}

bool VariableNode::evaluate(const std::map<std::string, bool> &assignment) const {
  // your code starts here
  if(assignment.find(getContent())!=assignment.end()){
    return assignment.at(getContent());
  }
  else{
    throw("Error: incomplete assignment");
  }
}

TreeNode::~TreeNode() {
  // your code starts here
  delete leftChild;
  delete rightChild;
}

