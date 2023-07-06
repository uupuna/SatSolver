// defined std::unique_ptr
#include <memory>
// defines Var and Lit
#include "minisat/core/SolverTypes.h"
// defines Solver
#include "minisat/core/Solver.h"

// #include "minisat/mtl/Vec.h"

// defined std::cout
#include <iostream>

#include "tseitinTransformer.h"
#include "satSolver.h"
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

                // -- allocate on the heap so that we can reset later if needed
                std::unique_ptr<Minisat::Solver> solver(new Minisat::Solver());

                unsigned int var_num = solution->getVarNum();
                Minisat::Lit* var_array = new Minisat::Lit[var_num];
                for (unsigned int tmp=0; tmp<var_num; tmp++){
                    var_array[tmp] = Minisat::mkLit(solver->newVar());
                }
                
                for (unsigned int cnf_i = 0; cnf_i < cnf.size(); cnf_i ++){
                    Minisat::vec<Minisat::Lit> vec_each_clause;
                    for (unsigned int cnf_j = 0; cnf_j < cnf[cnf_i].size(); cnf_j ++){
                        if(cnf[cnf_i][cnf_j]>0){
                            vec_each_clause.push(var_array[cnf[cnf_i][cnf_j]-1]);
                        }
                        else{
                            vec_each_clause.push(~var_array[-cnf[cnf_i][cnf_j]-1]);
                        }
                    }
                    solver->addClause(vec_each_clause);
                }

                bool res = solver->solve();
                // std::cout << "New result is: " << res << std::endl;

                // std::cout << "satisfying assignment is: " << std::endl;

                // for(unsigned int tmp=0;tmp<var_num;tmp++){
                //     std::cout << Minisat::toInt(solver->modelValue(var_array[tmp])) << std::endl;
                // }

                if(res){
                    std::cout << "sat" << "\n";
                }
                else{
                    std::cout << "unsat" << "\n";
                }
                solver.reset (new Minisat::Solver());
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
