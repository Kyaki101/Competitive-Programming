#include <bits/stdc++.h>

typedef std::vector<long long int> list;

long long int constant;
long long int ships;
list depths;
list quant;
list costs;
std::vector<list> memo;
list rout;

long long int gold(long long int index, long long int air){
    if(air < 0) return -(1<<30);
    if(index < 0 || air == 0)return 0;
    if(memo[index][air])return memo[index][air];
    memo[index][air] = std::max(gold(index - 1, air), quant[index] + gold(index - 1, air - costs[index]));
    return memo[index][air];
}

void router(long long int air, long long int index){
    if(air == 0 || index <= 0) return;
    if(memo[index][air] > memo[index - 1][air]){
        rout.push_back(index);
        return router(air - costs[index], index - 1);
    }
    if(memo[index][air] == memo[index - 1][air] && index - 1 == 0 && memo[index][air] != 0){
        rout.push_back(index - 1);
        return;
    }
    return router(air, index - 1);
}

int main(){
    long long int air;
    while(std::cin >> air >> constant){
        std::cin >> ships;
        rout.assign(0, 0);
        depths.assign(ships, 0);
        quant.assign(ships, 0);
        costs.assign(ships, 0);
        memo.assign(ships, list(air + 1, 0));
        for(long long int i = 0; i < ships; i ++){
            std::cin >> depths[i] >> quant[i];
            costs[i] = constant * depths[i] + (2 * constant * depths[i]);
        }
        std::cout << gold(ships - 1, air) << std::endl;
        // for(list i : memo){
        //     for(long long int j : i){ 
        //         std::cout << j << ' ';
        //     }
        //     std::cout << std::endl;
        // }
        router(air, ships - 1);
        std::sort(rout.begin(), rout.end());
        std::cout << rout.size() << '\n';
        for(long long int i: rout)std::cout << depths[i] << " " << quant[i] << std::endl;
    }
    return 0;
}