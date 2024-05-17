/*
*https://codeforces.com/gym/105167/problem/B
*/

#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;


ll expoLog(ll x){
    if(x == 0){
        return 1;
    }
    if(x & 1)
        return ((2 % MOD) * (expoLog(x - 1) % MOD)) % MOD;
    ll c = expoLog(x / 2);
    return ((c % MOD) * (c % MOD)) % MOD;
}


void bfs(vector<vector<ll> > & graph, vector<bool> & vis){
    ll curr = 0;
    queue<ll> cola;
    cola.push(1);
    ll res = 0;
    bool start = true;
    ll counter = 0;
    while(!cola.empty()){
        counter = 0;
        curr = cola.front();
        cola.pop();
        for(ll i : graph[curr]){
            if(!vis[i]){
                vis[i] = true;
                counter ++;
                cola.push(i);
            }

        }
        if(!counter){
            res = res;
        }

        else if(!start){
            ll pre = (expoLog(counter) - 1) % MOD;
            pre = ((pre % MOD) * (2 % MOD)) % MOD;
            res = ((pre % MOD) + (res % MOD)) % MOD;

        }
        else res = ((res % MOD) + ((expoLog(counter) - 1) % MOD)) % MOD;
        start = false;

    }
    cout << res << endl;
}


void sol(){
    ll n;
    cin >> n;
    vector<vector<ll> > adj(n + 1);
    ll a, b;
    for(int i = 1; i < n; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> vis(n + 1, false);
    vis[1] = true;
    bfs(adj, vis);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
              
    int t;
    t = 1;
    while(t--){
        sol();
    }


    return 0;
}

