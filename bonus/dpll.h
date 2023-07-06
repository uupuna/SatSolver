#ifndef DPLL_H
#define DPLL_H

#include <vector>
#include <map>

class DPLL
{
    private:
        std::vector<std::vector<int>> DPLL_cnf;
        std::map<int, bool> var_assignment;
        bool tmp_result;
    public:
        DPLL(std::vector<std::vector<int>> cnf);
        std::vector<std::vector<int>> bcp(std::vector<std::vector<int>> cnf);
        std::vector<std::vector<int>> plp(std::vector<std::vector<int>> cnf);
        bool dpll_rec(std::vector<std::vector<int>> cnf);
        int choose_var(std::vector<std::vector<int>> cnf);
        std::map<int, bool> get_var_assignment();
        bool use_dpll_rec();
        void print_cnf(std::vector<std::vector<int>> cnf);
};

#endif