#include "tseitinTransformer.h"
#include <vector>
#include <map>
#include <iostream>
// #include "treeNode.h"

TseitinTransformer::TseitinTransformer(TreeNode *root): formulaRoot(root) {}

int TseitinTransformer::transSubformula(TreeNode* subRoot, unsigned int curID) {
  // your code starts here
  if (subRoot->getContent() != "*" && subRoot->getContent() != "+" && subRoot->getContent() != "-")
    return 0;
  
  
  if (subRoot->getContent() == "*"){
    int leftID, rightID;
    if(subRoot->getLeftChild()->getContent()!="*" && subRoot->getLeftChild()->getContent()!="+" && subRoot->getLeftChild()->getContent()!="-"){
      if (varIdTable.find(subRoot->getLeftChild()->getContent()) == varIdTable.end()){
        leftID = ++varIdCounter;
        varIdTable[subRoot->getLeftChild()->getContent()] = leftID;
      }
      else leftID = varIdTable[subRoot->getLeftChild()->getContent()];
    }
    else{
      leftID = ++varIdCounter;
    }

    if(subRoot->getRightChild()->getContent()!="*" && subRoot->getRightChild()->getContent()!="+" && subRoot->getRightChild()->getContent()!="-"){
      if (varIdTable.find(subRoot->getRightChild()->getContent()) == varIdTable.end()){
        rightID = ++varIdCounter;
        varIdTable[subRoot->getRightChild()->getContent()] = rightID;
      }
      else rightID = varIdTable[subRoot->getRightChild()->getContent()];
    }
    else{
      rightID = ++varIdCounter;
    }
    
    addAndEq(curID, leftID, rightID);

    transSubformula(subRoot->getLeftChild(), leftID);
    transSubformula(subRoot->getRightChild(), rightID);
  }

  else if (subRoot->getContent() == "+"){
    int leftID, rightID;
    if(subRoot->getLeftChild()->getContent()!="*" && subRoot->getLeftChild()->getContent()!="+" && subRoot->getLeftChild()->getContent()!="-"){
      if (varIdTable.find(subRoot->getLeftChild()->getContent()) == varIdTable.end()){
        leftID = ++varIdCounter;
        varIdTable[subRoot->getLeftChild()->getContent()] = leftID;
      }
      else leftID = varIdTable[subRoot->getLeftChild()->getContent()];
    }
    else{
      leftID = ++varIdCounter;
    }

    if(subRoot->getRightChild()->getContent()!="*" && subRoot->getRightChild()->getContent()!="+" && subRoot->getRightChild()->getContent()!="-"){
      if (varIdTable.find(subRoot->getRightChild()->getContent()) == varIdTable.end()){
        rightID = ++varIdCounter;
        varIdTable[subRoot->getRightChild()->getContent()] = rightID;
      }
      else rightID = varIdTable[subRoot->getRightChild()->getContent()];
    }
    else{
      rightID = ++varIdCounter;
    }
    
    addOrEq(curID, leftID, rightID);

    transSubformula(subRoot->getLeftChild(), leftID);
    transSubformula(subRoot->getRightChild(), rightID);
  }

  else if (subRoot->getContent() == "-"){
    int childID;
    if(subRoot->getLeftChild()->getContent()!="*" && subRoot->getLeftChild()->getContent()!="+" && subRoot->getLeftChild()->getContent()!="-"){
      if (varIdTable.find(subRoot->getLeftChild()->getContent()) == varIdTable.end()){
        childID = ++varIdCounter;
        varIdTable[subRoot->getLeftChild()->getContent()] = childID;
      }
      else childID = varIdTable[subRoot->getLeftChild()->getContent()];
      addNegEq(curID, childID);
      transSubformula(subRoot->getLeftChild(),childID);
    }
    else{
      childID = ++varIdCounter;
      addNegEq(curID, childID);
      transSubformula(subRoot->getLeftChild(),childID);
    }
  }

  return 0;
}

void TseitinTransformer::addNegEq(int curID, int childID) {
  // your code starts here
  cnf.insert(cnf.begin(),{curID,childID});
  cnf.insert(cnf.begin(),{-curID,-childID});
}

void TseitinTransformer::addOrEq(int curID, int leftID, int rightID) {
  // your code starts here
  cnf.insert(cnf.begin(),{-rightID,curID});
  cnf.insert(cnf.begin(),{-leftID,curID});
  cnf.insert(cnf.begin(),{-curID,leftID,rightID});
}

void TseitinTransformer::addAndEq(int curID, int leftID, int rightID) {
  // your code starts here
  cnf.insert(cnf.begin(),{-leftID,-rightID,curID});
  cnf.insert(cnf.begin(),{-curID,rightID});
  cnf.insert(cnf.begin(),{-curID,leftID});
  
}

std::vector<std::vector<int>> TseitinTransformer::transform() {
  // your code starts here
  transSubformula(formulaRoot, 1);
  cnf.insert(cnf.end(),{1});
  return cnf;
}

std::string TseitinTransformer::cnfString() const {
  std::string result = "";
  // your code starts here
  // std::cout<<"in vector"<<std::endl;
  for (unsigned int i = 0; i < cnf.size(); i ++){
    result += '[';
    // std::cout<<"in vector: "<<i<<std::endl;
    for (unsigned int j = 0; j < cnf[i].size(); j ++){
      if(cnf[i][j]<0){
        result += '-';
        result += std::to_string(-cnf[i][j]);
      }
      else{
        result += std::to_string(cnf[i][j]);
      }
      result += ',';
      // std::cout<<cnf[i][j]<<std::endl;
    }
    result = result.substr(0, result.length() - 1);
    result += ']';
  }
  return result;
}

unsigned int TseitinTransformer::getVarNum() const {
  // your code starts here
  return varIdCounter;
}


// int main(){
//   // test 1
//   // TreeNode* root = new OperatorNode("v1");

//   // test 2
//   // TreeNode* root = new OperatorNode("+");
//   // TreeNode* left = new VariableNode("c");
//   // TreeNode* right = new VariableNode("d");
//   // root->assignLeftChild(left);
//   // root->assignRightChild(right);

//   // test 3
//   // TreeNode* root = new OperatorNode("-");
//   // TreeNode* left = new VariableNode("b");
//   // root->assignLeftChild(left);

//   // test 4
//   TreeNode* root = new OperatorNode("*");
//   TreeNode* left = new VariableNode("c");
//   TreeNode* right = new VariableNode("+");
//   root->assignLeftChild(left);
//   root->assignRightChild(right);
//   TreeNode* right1 = new VariableNode("d");
//   TreeNode* right2 = new VariableNode("c");
//   right->assignLeftChild(right1);
//   right->assignRightChild(right2);

//   TseitinTransformer* solution = new TseitinTransformer(root);
//   solution->transform();
//   std::cout<<solution->cnfString()<<std::endl;
//   return 0;
// }