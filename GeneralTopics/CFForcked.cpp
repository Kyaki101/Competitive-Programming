#include <bits/stdc++.h>



typedef long long int ll;

typedef std::vector<ll> list;

ll a;
ll b;

std::vector<list> moves;
std::set<std::pair<ll, ll>> memo;
std::set<std::pair<ll, ll>> ver;

ll xk;
ll yk;

ll xq;
ll yq;

void sol(){
    ll counter = 0;
    for(ll i = 0; i < 8; i++){
        memo.insert(std::make_pair(xk + moves[i][0], yk + moves[i][1]));
    }
    for(ll i = 0; i < 8; i++){
        auto it = memo.find(std::make_pair(xq + moves[i][0], yq + moves[i][1]));
        auto el = ver.find(std::make_pair(xq + moves[i][0], yq + moves[i][1]));
        if(it != memo.end() && el == ver.end()){
            counter ++;
            ver.insert(std::make_pair(xq + moves[i][0], yq + moves[i][1]));
        }
    }
    std::cout << counter << '\n';
}

int main(){
    ll t;
    std::cin >> t;
    while(t--){
        memo.clear();
        ver.clear();
        std::cin >> a >> b;
        std::cin >> xk >> yk;
        std::cin >> xq >> yq;
        moves = {{-a, b}, {-a, -b}, {-b, -a}, {b, -a}, {a, -b}, {a, b}, {b, a}, {-b, a}};
        sol();
    }
}