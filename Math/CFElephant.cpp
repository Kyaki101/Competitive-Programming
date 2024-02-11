/*
https://codeforces.com/problemset/problem/617/A
*/

#include <iostream>

int main(){
    long long int n;
    std::cin >> n;
    if(n % 5 == 0)std::cout << n / 5 << '\n';
    else std::cout << n / 5 + 1 << '\n';


    return 0;
}