#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cmath>
#include "dpll.h"

DPLL::DPLL(std::vector<std::vector<int>> cnf):DPLL_cnf(cnf){}

std::vector<std::vector<int>> DPLL::bcp(std::vector<std::vector<int>> cnf){
    std::vector<std::vector<int>> bcp_cnf(cnf);
    tmp_result = true;
    while(1){
        // std::cout<<"in each bcp loop:"<<std::endl;
        // print_cnf(bcp_cnf);
        int single_var;
        for (unsigned int i = 0; i < bcp_cnf.size(); i ++){
            if (bcp_cnf[i].size() == 1){
                single_var = bcp_cnf[i][0];
                if (single_var > 0)
                    var_assignment[single_var] = true;
                else if (single_var < 0)
                    var_assignment[-single_var] = false;
                break;
            }
        }
        // std::cout<<"in each bcp loop, after select var: "<<single_var<<std::endl;
        for (int i = 0; i < bcp_cnf.size(); i ++){
            for (int j = 0; j < bcp_cnf[i].size(); j ++){
                if (single_var==bcp_cnf[i][j]){
                    bcp_cnf.erase(bcp_cnf.begin()+i);
                    i--;
                    break;
                }
                else if (single_var==-bcp_cnf[i][j]){
                    if(bcp_cnf[i].size()==1){
                        tmp_result = false;
                        return bcp_cnf;
                    }
                    bcp_cnf[i].erase(bcp_cnf[i].begin()+j);
                    j--;
                }
            }
        }
        if(bcp_cnf.size()==0){
            return bcp_cnf;
        }
        bool flag = true;
        for (unsigned int i = 0; i < bcp_cnf.size(); i ++){
            if (bcp_cnf[i].size() == 1){
                flag = false;
            }
        }
        if (flag)
            break;
    }
    return bcp_cnf;
}

std::vector<std::vector<int>> DPLL::plp(std::vector<std::vector<int>> cnf){
    std::vector<std::vector<int>> plp_cnf(cnf);
    std::map<int, bool> all_var;
    for (unsigned int i = 0; i < plp_cnf.size(); i ++){
        for (unsigned int j = 0; j < plp_cnf[i].size(); j ++){
            if(all_var.find(plp_cnf[i][j])==all_var.end()){
                all_var[plp_cnf[i][j]] = true;
            }
        }
    }
    std::map<int, bool> pure_var;
    for(std::map<int, bool>::iterator iter=all_var.begin(); iter!=all_var.end(); iter++)
    {
        int tmp = iter->first;
        if (all_var.find(-tmp)==all_var.end()){
            pure_var[tmp] = true;
            if (pure_var[tmp] > 0){
                var_assignment[pure_var[tmp]] = true;
            }
            else var_assignment[-pure_var[tmp]] = false;
        }
    }

    for (int i = 0; i < plp_cnf.size(); i ++){
        for (int j = 0; j < plp_cnf[i].size(); j ++){
            if (pure_var.find(plp_cnf[i][j])!=pure_var.end()){
                plp_cnf.erase(plp_cnf.begin()+i);
                i--;
                break;
            }
        }
    }
    return plp_cnf;
}

// void DPLL::print_cnf(std::vector<std::vector<int>> cnf){
//     std::string result = "";
//     for (unsigned int i = 0; i < cnf.size(); i ++){
//         result += '[';
//         // std::cout<<"in vector: "<<i<<std::endl;
//         for (unsigned int j = 0; j < cnf[i].size(); j ++){
//         if(cnf[i][j]<0){
//             result += '-';
//             result += std::to_string(-cnf[i][j]);
//         }
//         else{
//             result += std::to_string(cnf[i][j]);
//         }
//         result += ',';
//         // std::cout<<cnf[i][j]<<std::endl;
//         }
//         result = result.substr(0, result.length() - 1);
//         result += ']';
//     }
//     std::cout<<"in print cnf:"<<result<<std::endl;
// }


bool DPLL::dpll_rec(std::vector<std::vector<int>> cnf){
    if(cnf.size()==0){
        return true;
    }
    std::vector<std::vector<int>> bcp_cnf = bcp(cnf);
    if (bcp_cnf.size() == 0)
        return true;
    if (tmp_result == false){
        return false;
    }
        
    std::vector<std::vector<int>> plp_cnf = plp(bcp_cnf);
    if (plp_cnf.size() == 0)
        return true;

    int var = choose_var(plp_cnf);
    // std::cout<< "in dpll_rec: var:" << var << "is true " << std::endl;
    var_assignment[var]=true;
    std::vector<std::vector<int>> tmp(plp_cnf);
    for (int i = 0; i < plp_cnf.size(); i ++){
        // std::cout<< "in dpll_rec: i=" << i << std::endl;
        std::vector<int>::iterator it = find(plp_cnf[i].begin(), plp_cnf[i].end(), var);
        std::vector<int>::iterator it2 = find(plp_cnf[i].begin(), plp_cnf[i].end(), -var);
        if (it != plp_cnf[i].end()){
            plp_cnf.erase(plp_cnf.begin()+i);     
            i--;       
        }
        else if (it2 != plp_cnf[i].end())
            plp_cnf[i].erase(it2);
        // print_cnf(plp_cnf);
    }

    if (dpll_rec(plp_cnf)){
        return true;
    }
    else{
        // std::cout<< "in dpll_rec: var:" << var << "is false " << std::endl;
        var_assignment[var] = false;
        for (int i = 0; i < tmp.size(); i ++){
            std::vector<int>::iterator it = find(tmp[i].begin(), tmp[i].end(), var);
            std::vector<int>::iterator it2 = find(tmp[i].begin(), tmp[i].end(), -var);
            if (it2 != tmp[i].end()){
                tmp.erase(tmp.begin()+i);
                i--;
            }
            else if (it != tmp[i].end())
                tmp[i].erase(it);
        }
        return dpll_rec(tmp);
    }
}

int DPLL::choose_var(std::vector<std::vector<int>> cnf){
    return abs(cnf[0][0]);
}

std::map<int, bool> DPLL::get_var_assignment(){
    return var_assignment;
}


bool DPLL::use_dpll_rec(){
    return dpll_rec(DPLL_cnf);
}

