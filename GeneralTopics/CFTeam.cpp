#include <bits/stdc++.h>

typedef std::vector<int> list;

int n;
int a, b, c;
int counter = 0;


int main(){
    std::cin >> n;
    for(int i = 0; i < n; i++){
        std::cin >> a >> b >> c;
        if(a + b + c >= 2)counter ++;
    }
    std::cout << counter << '\n';
}