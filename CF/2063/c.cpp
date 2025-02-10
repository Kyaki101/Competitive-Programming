#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename Key, typename Value>
using ordered_map = tree<Key, Value, less<Key>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename Key, typename Value = null_type>
using trie = trie<Key, Value, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update>;
#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) (cout << (n) << endl)
#define CLEAN(arr) (memset(arr, 0, sizeof(arr)))
#define ALL(v) (v).begin(), (v).end()


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

const int MAX = 2e5+20;


struct UnionFind{
    vector<int> uf;
    void init(int n){uf.assign(n, -1);}
    int Find(int i){return (uf[i]==-1)? i : uf[i] = Find(uf[i]);}
    bool Union(int i, int j){
        bool e = Find(i)==Find(j);
        if(!e) uf[Find(i)] = Find(j);
        return e;
    }
};


ll maxi = -1;
ll nodeM;

void dfsW(ll node, vector<vector<ll> > & g, vector<bool> & vis, ll prem, vector<ll> & maxis, vector<bool> & bruh) {
    vis[node] = true;
    if(g[node].size() == prem) {
        bruh[node] = true;
        nodeM = node;
    }
    for(int i = 0; i < g[node].size(); i++) {
        if(g[g[node][i]].size() == prem && g[node].size() == prem) maxis[node] ++;
        if(!vis[g[node][i]]) dfsW(g[node][i], g, vis, prem, maxis, bruh);
    }
    
}




void dfs(ll node, vector<vector<ll> > & g, vector<bool> & vis) {
    vis[node] = true;
    if(g[node].size() > maxi) {
        maxi = g[node].size();
        nodeM = node;
    }
    for(int i = 0; i < g[node].size(); i++) {
        if(!vis[g[node][i]]) dfs(g[node][i], g, vis);
    }
    
}

void sol(){        
    ll n;
    cin >> n;
    vector<vector<ll> > g(n);
    ll prem = 0;
    for(int i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        a --; b --;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<ll> maxis(n, 0);
    for(int i = 0; i < n; i++) {
        if(g[i].size() > prem) prem = g[i].size();
    }
    maxi = 0;
    vector<bool> vis(n, false);
    vector<bool> bruh(n, false);

    dfsW(0, g, vis, prem, maxis, bruh);
    ll maxiVal = 0;
    for(int i = 0; i < n; i ++) {

        if(bruh[i]) {
            if(maxis[i] <= maxiVal) {
                nodeM = i;
                maxiVal = maxis[i];
            }
        }
    }


    ll ans = 0;

    ans += prem;


    vector<vector<ll> > g2(n);

    for(int i = 0; i < n; i++) {
        if(i != nodeM) for(ll j : g[i]) {
            if(j != nodeM) {
                g2[i].push_back(j);
            }
            
        }
    }




    maxi = 0;
    vis.assign(n, false);

    for(int i = 0; i < n; i++) {
        if(i != nodeM && !vis[i]) {
            dfs(i, g2, vis);
        }
    }


    maxi --;

    

   
    cout << ans + maxi << endl;


    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

              
    int t;
    cin >> t;
    while(t--){
        sol();
    }


    return 0;
}

