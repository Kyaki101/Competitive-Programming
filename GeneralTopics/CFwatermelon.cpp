#include <iostream>

int main(){
    int n;
    std::cin >> n;
    if(n == 2)std::cout << "NO" << '\n';
    else if(n & 1)std::cout << "NO" << '\n';
    else std::cout << "YES" << '\n';
}