#include <iostream>

int main(){
    int t;
    std::cin >> t;
    std::string st;
    while(t--){
        std::cin >> st;
        if(st.size() > 10){
            std::cout << st[0] << st.size() - 2 << st[st.size() - 1] << '\n';
        }
        else std::cout << st << '\n';
    }
}