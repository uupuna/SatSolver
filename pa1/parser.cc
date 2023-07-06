#include "parser.h"
#include "treeNode.h"
#include "tokenizer.h"
#include<iostream>
#include<algorithm>

FormulaParser::FormulaParser(std::string ln): tknzr (new Tokenizer(ln)) {}

TreeNode *FormulaParser::parseFormula() {
  // your code starts here
  bool flag=true;
  std::string str="\0";
  TreeNode* t2=nullptr;
  int left_num=0,right_num=0;
  while(tknzr->advanceToken()){
    if(tknzr->hasToken()){
        Token tmp=tknzr->getToken();
        left_num=count(str.begin(),str.end(),'(');
        right_num=count(str.begin(),str.end(),')');
        if((tmp.content=="+")&&(left_num==right_num)){
           flag=false;
           t2=parseFormula();
           break;
        }
        else str += tmp.content;
    }
  }
  tknzr=new Tokenizer(str);
  TreeNode* t1=parseConjTerm();
  if(flag){
    return t1;
  }
  else {
    OperatorNode* orNode=new OperatorNode("+");
    orNode->updateChildren(t1,t2);
    return orNode;
  }
}

TreeNode *FormulaParser::parseConjTerm() {
  // your code starts here
  bool flag=true;
  TreeNode* t2=nullptr;
  std::string str="\0";
  int left_num=0,right_num=0;
  while(tknzr->advanceToken()){
    if(tknzr->hasToken()){
        Token tmp=tknzr->getToken();
        left_num=count(str.begin(),str.end(),'(');
        right_num=count(str.begin(),str.end(),')');
        if((tmp.content=="*")&&(left_num==right_num)){
           flag=false;
           t2=parseConjTerm();
           break;
          }
        else str+=tmp.content;
    }
  }
  tknzr=new Tokenizer(str);
  TreeNode* t1=parseTerm();
  if(flag){
    return t1;
  }
  else{
    OperatorNode* andNode=new OperatorNode("*");
    andNode->updateChildren(t1,t2);
    return andNode;
  }

}
TreeNode *FormulaParser::parseTerm() {
  // your code starts here
  std::string str="\0";
  std::string str2="\0";

  while(tknzr->advanceToken()){
    if(tknzr->hasToken()){
        Token tmp=tknzr->getToken();
        if(tmp.content=="("){
            Token tmp2;
            while(tknzr->advanceToken()){
                if(tknzr->hasToken()){
                    tmp2=tknzr->getToken();
                    str2+=tmp2.content;
                }
            }
            if(tmp2.content!=")"){
                throw("Error: invalid input");
            }
            else{
                str2.erase(str2.end()-1);
                tknzr=new Tokenizer(str2);
                return parseFormula();
            }
        }
        else if(tmp.content=="-"){
            TreeNode* t1=parseTerm();
            OperatorNode* notNode=new OperatorNode("-");
            notNode->updateLeftChild(t1);
            return notNode;
        }
        else if(tmp.type=="constant"){
            if(tknzr->advanceToken()){
                throw("Error: invalid input");
            }
            else{
                ConstantNode* conNode=new ConstantNode(tmp.content);
                return conNode;
            }
        }
        else if(tmp.type=="variable"){
            if(tknzr->advanceToken()){
                 throw("Error: invalid input");
            }
            else{
                 VariableNode* varNode=new VariableNode(tmp.content);
                 return varNode;
            }
        }
        else{
            throw("Error: invalid input");
        }
    }
  }
  return nullptr;
}

TreeNode * FormulaParser::getTreeRoot() {
  // your code starts here
  return parseFormula();
}

FormulaParser::~FormulaParser() {
  // your code starts here
  delete tknzr;
}

AssignmentParser::AssignmentParser(std::string ln): tknzr {new Tokenizer{ln}} {}

std::map<std::string, bool> AssignmentParser::parseAssignment() {
  std::map<std::string, bool> results;
  // your code starts here
  std::string str="\0";
  Token tmp, tmp2;
  while(1){
    if(tknzr->advanceToken()){
        if(tknzr->hasToken()){
            tmp=tknzr->getToken();
            if(tmp.type!="variable"){
                throw("Error: invalid input");
            }
        }
    }
    else{
        throw("Error: invalid input");
    }

    if(tknzr->advanceToken()){
        if(tknzr->hasToken()){
            tmp2=tknzr->getToken();
            if(!(tmp2.type=="operator"&&tmp2.content==":")){
                throw("Error: invalid input");
            }
        }
    }
    else{
        throw("Error: invalid input");
    }

    if(tknzr->advanceToken()){
        if(tknzr->hasToken()){
            tmp2=tknzr->getToken();
            if(tmp2.type!="constant"){
                throw("Error: invalid input");
            }
        }
    }
    else{
        throw("Error: invalid input");
    }

    std::map<std::string, bool>::iterator iter = results.find(tmp.content);
    if(iter != results.end()){
        bool prev = results[tmp.content];
        if(prev){
            if(tmp2.content!="1"){
                throw("Error: contradicting assignment");
            }
        }
        else{
            if(tmp2.content!="0"){
                throw("Error: contradicting assignment");
            }
        }
    }
    else{
        if(tmp2.content == "1"){
            results[tmp.content] = true;
        }
        else if(tmp2.content == "0"){
            results[tmp.content] = false;
        }
    }

    bool continue_flag=false;
    if(tknzr->advanceToken()){
        if(tknzr->hasToken()){
            tmp2=tknzr->getToken();
            if(tmp2.type=="operator"&&tmp2.content==","){
                continue_flag=true;
            }
            else{
                throw("Error: invalid input");
            }
        }
    }
    if(!continue_flag)
        break;
  }
  return results;
}

AssignmentParser::~AssignmentParser() {
  // your code starts here
  delete tknzr;
}
