#include <bits/stdc++.h>

int a, b;

int main(){
    int t;
    std::cin >> t;
    while(t--){
        std::cin >> a >> b;
        if(std::lcm(a, b) == b){
            std::cout << b * (b / a) << std::endl;
        }
        else{
            std::cout << std::lcm(a, b) << std::endl;
        }
    }
}