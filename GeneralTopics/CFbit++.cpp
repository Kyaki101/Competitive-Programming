#include <bits/stdc++.h>
typedef long long int ll;

int main(){
    int t;
    std::cin >> t;
    std::string pre;
    bool symb;
    int res = 0;
    while(t--){
        std::cin >> pre;
        for(char i : pre){
            if(i == '+')symb = true;
            if(i == '-')symb = false;
        }
        if(symb) res ++;
        if(!symb) res --;
    }
    std::cout << res << std::endl;

    return 0;
}