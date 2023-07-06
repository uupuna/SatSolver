#include "tokenizer.h"
#include<iostream>

Tokenizer::Tokenizer(std::string ln) {
  // complete the constructor
  line = ln;
  currentToken.content = "";
  currentToken.type = "none";
}

bool Tokenizer::advanceToken() {
  // your code starts here
  unsigned int i=0;
  if(line.length()==0||i==line.length())
    return false;
  else{
    for(;i<line.length();){
      if(line[i]=='0'||line[i]=='1'){
        if((i+1<line.length())&&((line[i+1]>='a'&&line[i+1]<='z')||(line[i+1]>='A'&&line[i+1]<='Z')||(line[i+1]>='0'&&line[i+1]<='9'))){
           std::cout << "Error: invalid input" << std::endl;
           return false;
        }
        else{
           currentToken.content=line[i];
           currentToken.type="constant";
           i++;
           line.erase(0,i);
           return true;
        }

      }
      else if((line[i]>='a'&&line[i]<='z')||(line[i]>='A'&&line[i]<='Z')){
        currentToken.type="variable";
        currentToken.content=line[i];
        i++;
        while(i<line.length()&&((line[i]>='a'&&line[i]<='z')||(line[i]>='A'&&line[i]<='Z')||(line[i]>='0'&&line[i]<='9'))){
          currentToken.content +=line[i];
          i++;
        }
        while(i<line.length()&&line[i]==' '){
            i++;
            if(i<line.length()&&((line[i]>='a'&&line[i]<='z')||(line[i]>='A'&&line[i]<='Z')||(line[i]>='0'&&line[i]<='9'))){
                throw("Error: invalid input");
            }
        }
        if(currentToken.content.length()<=10){
            line.erase(0,i);
            return true;
        }
        else{
          throw("Error: invalid input");
        }

      }
      else if(line[i]=='('||line[i]==')'||line[i]=='+'||line[i]=='-'||line[i]=='*'){
        currentToken.content=line[i];
        currentToken.type="operator";
        i++;
        line.erase(0,i);
        return true;
      }
      else if(line[i]==' '){
        i++;
        continue;
      }
      else if(line[i]>='2'&&line[i]<='9'){
        throw("Error: invalid input");
      }
      else if(line[i]==':'||','){
        currentToken.content=line[i];
        currentToken.type="operator";
        i++;
        line.erase(0,i);
        return true;
      }
      else{
        throw("Error: invalid input");
      }
    }
  }
  return false;
}

bool Tokenizer::hasToken() const {
  // your code starts here
  if(currentToken.content!="") return true;
  else return false;
}

// only can be called when hasToken() is true
Token Tokenizer::getToken() {
  Token resultToken;
  // your code starts there
  resultToken.content = currentToken.content;
  resultToken.type = currentToken.type;
  currentToken.content = "";
  currentToken.type = "none";

  return resultToken;
}

