#include <bits/stdc++.h>

int res;

int memo = 0;

int a, b, c;

bool TEST(int msk, int i){
    return (msk & (1 << i));
}

int SET(int msk, int i){
    return (msk | (1 << i));
}

int main(){
    int t;
    std::cin >> t;
    while(t--){
        memo = 0;
        std::cin >> a >> b >> c;
        memo = SET(memo, a);
        if(TEST(memo, b)){
            std::cout << c << '\n';
        }
        else{
            memo = SET(memo, b);
            if(c == a){
                std::cout << b << std::endl;
            }
            else{std::cout << a << std::endl;}
        }

    }
}