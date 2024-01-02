#include <bits/stdc++.h>


typedef long long int ll;

typedef std::vector<ll> list;

int q;
int e;
list quests;
list a;
list b;


void sol(){
    ll sum = 0;
    ll res = 0;
    ll max = 0;
    for(int i = 0; i < std::min(q, e); i++){
        sum += a[i];
        max = std::max(max, b[i]);
        res = std::max(res, sum + max * (e - i - 1));
    }
    std::cout << res << '\n';
}


int main(){
    int t;
    std::cin >> t;
    while(t--){
        std::cin >> q >> e;
        a.assign(q, 0);
        b.assign(q, 0);
        for(int i = 0; i < q; i++){
            std::cin >> a[i];
        }
        for(int i = 0; i < q; i++){
            std::cin >> b[i];
        }
        sol();
    }
}