#include <bits/stdc++.h>

typedef long long int ll;

ll n;
ll sum = 0;
ll temp;

bool bb(){
    long long int sqr = sqrt(sum);
    return sqr * sqr == sum;
}

void sol(){
    if(bb()){std::cout << "YES\n"; return;}
    std::cout << "NO\n";
}


int main(){
    int t;
    std::cin >> t;
    while(t--){
        std::cin >> n; 
        sum = 0;
        for(int i = 0; i < n; i++){
            std::cin >> temp; sum += temp;
        }
        sol();
    }
}