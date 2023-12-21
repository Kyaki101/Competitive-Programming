#include <bits/stdc++.h>

std::vector<std::set<std::string>> memo(9);

std::set<std::string> func(int n){
    if(n == 1) return {"()"};
    if(!memo[n].empty()) return memo[n];
    std::set<std::string> result;
    std::string pre;
    for(std::string s : func(n - 1)){
        pre = "(";
        pre += s;
        pre += ")";
        result.insert(pre);
        pre = "";
    }
    int i = 1;
    int j = n - 1;
    while(i <= j){
        for(std::string uno: func(j)){
            for(std::string dos: func(i)){
                pre = uno + dos;
                result.insert(pre);
                pre = "";
                pre = dos + uno;
                result.insert(pre);
                pre = "";
            }

        }
        i++; j--;
    }
    memo[n] = result;
    return memo[n];
}



class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::set<std::string> pre;
        pre = func(n);
        std::vector<std::string> fin;
        for(std::string i : pre) fin.push_back(i);
        return fin;
    }
};