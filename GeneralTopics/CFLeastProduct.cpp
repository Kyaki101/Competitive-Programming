#include <bits/stdc++.h>

int n;
std::vector<int> list;

void sol(){
    int negatives = 0;
    for(int i = 0; i < n; i++){
        if(list[i] < 0) negatives ++;
        if(list[i] == 0){std::cout << "0\n"; return;}
    }
    if(!(negatives & 1)){
        std::cout << "1\n1 0\n"; 
    }
    else std::cout << "0\n";
}

int main(){
    int t;
    std::cin >> t;
    while(t--){
        std::cin >> n;
        list.assign(n, 0);
        for(int i =0; i < n; i++){
            std::cin >> list[i];
        }
        sol();
    }

    return 0;
}