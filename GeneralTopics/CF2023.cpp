#include<bits/stdc++.h>
int n;
int k;
int prod = 1;
std::vector<int> array;

void sol(){
    bool bad = false;
    if(2023 % prod != 0)bad = true;
    if(bad){
        std::cout << "NO\n"; return;
    }
    std::cout << "YES\n";
    std::cout << 2023/prod;
    for(int i = 1; i < k; i++)std::cout << " " << 1;
    std::cout << '\n';

}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while(t--){
        std::cin >> n >> k;
        array.assign(n, 0);
        prod = 1;
        for(int i = 0; i < n; i ++){
            int temp;
            std::cin >> temp;
            prod *= temp;
            array[i] = temp;
        }
        sol();
    }
}