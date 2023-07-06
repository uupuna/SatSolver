#include <iostream>
#include <string>
#include <map>
#include "parser.h"
#include "treeNode.h"
#include <exception>

// a helper function parsing the input into the formula string and the assignment string
void parseLine(const std::string &line, std::string &formulaStr, std::string &assignmentStr) {
  // your code starts here
  if(line.find(";")==line.npos){
    throw("Error: invalid input");
  }
  else{
    if(line.find(";")==line.length()-1){
      formulaStr=line.substr(0,line.find(";"));
      assignmentStr=" ";
    }
    else{
      formulaStr=line.substr(0,line.find(";"));
      assignmentStr=line.substr(line.find(";")+1,line.length());
    }
  } 
}

// The program shall continuously ask for new inputs from standard input and output to the standard output
// The program should terminate gracefully (and quietly) once it sees EOF
int main() {
  while (true) // continuously asking for new inputs from standard input
  {
    std::string line; // store each input line
    std::string formulaStr; // store the formula string
    std::string assignmentStr; // store the assignment string
    // your code starts here
    while(!std::cin.eof()){
      try{
        if(!getline(std::cin,line)){
          return 0;
        }
        parseLine(line,formulaStr,assignmentStr);

        unsigned int i=0;
        int count_left=0;
        int count_right=0;
        bool flag=false;
        for(;i<formulaStr.length();i++){
          if((formulaStr[i]>='a'&&formulaStr[i]<='z')||(formulaStr[i]>='A'&&formulaStr[i]<='Z')){
              flag=true;
          }
          if(formulaStr[i]=='('){
              count_left++;
          }
          else if(formulaStr[i]==')'){
              count_right++;
          }
        }

        if(assignmentStr.length()==0&&flag){
            throw("Error: incomplete assignment");
            continue;
        }
        if(count_left!=count_right||formulaStr.length()==0){
            throw("Error: invalid input");
            continue;
        }
        
        FormulaParser f(formulaStr);
        bool all_assign_blank = true;
        for(i=0;i<assignmentStr.length();i++){
            if(assignmentStr[i]==' '){
              continue;
            }
            else{
              all_assign_blank = false;
              break;
            }
        }
      
        if(assignmentStr.find_last_of(",")!=assignmentStr.npos){
            i=assignmentStr.find_last_of(",");
            unsigned int j = i+1;
            while(j<assignmentStr.length()){
            if(assignmentStr[j] == ' ') j++;
            else break;
            }
            if(j==assignmentStr.length()){
              assignmentStr.erase(i);
            } 
        }
        bool all_assign_blank2 = true;
        for(i=0;i<assignmentStr.length();i++){
            if(assignmentStr[i]==' '){
              continue;
            }
            else{
              all_assign_blank2 = false;
              break;
            }
        }
        if(all_assign_blank==false&&all_assign_blank2==true){
          throw("Error: invalid input");
        }

        if(assignmentStr.length()!=0 && !all_assign_blank){
            AssignmentParser ass(assignmentStr);
            std::map<std::string, bool> results = ass.parseAssignment();
            if(results.size()==0){
              continue;
            }
            TreeNode* root = f.getTreeRoot();
            if(root==nullptr){
              continue;
            }
            std::cout << root->evaluate(results) << std::endl;
            continue;
        }
        else{
            TreeNode* root = f.getTreeRoot();
            if(root==nullptr){
              continue;
            }
            std::map<std::string, bool> results;
            
            std::cout << root->evaluate(results) << std::endl;
            continue;
        }
      }
      catch(const char* msg)
      {
        std::cout<< msg <<std::endl;
      }
    }
  break;
  }
  return 0;
}
