#ifndef TNODE_H
#define TNODE_H

#include <string>

// abstract superclass of the syntax tree node
class TreeNode {
    std::string content;
    TreeNode *leftChild = nullptr;
    TreeNode *rightChild = nullptr;

  public:
    TreeNode(std::string cntt): content(cntt){}
    // your code starts here
    std::string getContent() const {
      return content;
    }
    TreeNode *getLeftChild() const {
      return leftChild;
    }
    TreeNode *getRightChild() const {
      return rightChild;
    }
    void assignLeftChild(TreeNode* left) {
      leftChild = left;
    }
    void assignRightChild(TreeNode* right) {
      rightChild = right;
    }
    void updateLeftChild(TreeNode *lChild) {
    if(lChild!=nullptr){
      leftChild=lChild;
    }
    else{
      throw("Error: invalid input");
    }
  }

  void updateChildren(TreeNode *lChild, TreeNode *rChild) {
    
    if(lChild!=nullptr&&rChild!=nullptr){
      leftChild=lChild;
      rightChild=rChild;
    }
    else{
      throw("Error: invalid input");
    }
  }

};

// concrete tree node of opertaor type
class OperatorNode : public TreeNode {
  public:
    OperatorNode(std::string cntt): TreeNode(cntt) {};
    // your code starts here
};

// concrete tree node of varibale type
class VariableNode : public TreeNode {
  public:
    VariableNode(std::string cntt): TreeNode(cntt) {};
    // your code starts here
};

#endif
