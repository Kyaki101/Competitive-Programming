#include <bits/stdc++.h>

typedef std::string str;

str s;
int one = 0;
int zero = 0;


void sol(){
    for(char i: s){
        if(i == '1')one ++;
        else zero ++;
    }
    int i = 0;
    if(!one || !zero){std::cout << s.size() << '\n'; return;}
    bool cont = true;
    while(cont && i < s.size()){
        if(s[i] == '1' && zero > 0){zero --; i++;}
        else if(s[i] == '1' && !zero)cont = false;
        else if(s[i] == '0' && one > 0) {one --; i++;}
        else if(s[i] == '0' && !one)cont = false;
    }
    std::cout << s.size() - i << '\n';
}

int main(){
    int t;
    std::cin >> t;
    while(t--){
        one = 0;
        zero = 0;
        std::cin >> s;
        sol();
    }
}