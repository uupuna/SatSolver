// defined std::unique_ptr
#include <memory>
#include "dpll.h"

// #include "minisat/mtl/Vec.h"

// defined std::cout
#include <iostream>

#include "tseitinTransformer.h"
#include <string>
#include <map>
#include "parser.h"
#include "treeNode.h"
#include <exception>

int main(void) {
    while (true) // continuously asking for new inputs from standard input
    {
        std::string line; // store each input line
        // your code starts here
        while(!std::cin.eof()){
            try{
                if(!getline(std::cin,line)){
                return 0;
                }

                unsigned int i=0;
                int count_left=0;
                int count_right=0;
                for(;i<line.length();i++){
                if(line[i]=='('){
                    count_left++;
                }
                else if(line[i]==')'){
                    count_right++;
                }
                }

                if(count_left!=count_right||line.length()==0){
                    throw("Error: invalid input");
                    continue;
                }

                FormulaParser f(line);
                TreeNode* root = f.getTreeRoot();
                TseitinTransformer* solution = new TseitinTransformer(root);
                std::vector<std::vector<int>> cnf = solution->transform();
                
                // std::cout << solution->cnfString() << std::endl;;
                DPLL* dpll_solver = new DPLL(cnf);
                bool res = dpll_solver->use_dpll_rec();

                if(res){
                    std::cout << "sat" << "\n";
                }
                else{
                    std::cout << "unsat" << "\n";
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
