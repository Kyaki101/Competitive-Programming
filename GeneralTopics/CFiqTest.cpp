#include <bits/stdc++.h>

int main(){
    int t;
    std::cin >> t;
    int n;
    int oddC = 0;
    int evenC = 0;
    int lastE;
    int lastO;
    for(int i = 0; i < t; i++){
        std::cin >> n;
        if(n % 2 != 0){
            lastO = i + 1;
            oddC ++;
        }
        else{
            lastE = i +1;
            evenC ++;
        }
    }
    if(evenC > oddC)std::cout << lastO << std::endl;
    else std::cout << lastE << std::endl;
    return 0;
}