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

ll val = 1;

bool cond = true;

void dfs(vector<vector<ll>> & graph, ll node, ll parent, vector<ll> & res, vector<bool> & vis) {
    if(parent == -1) {
        res[node] = val;
        for(ll i : graph[node]) {
            val ++;
            vis[i] = true;
            dfs(graph, i, res[node], res, vis);
        }
        return;
    }
    res[node] = val;
    if(abs(res[node] - parent) % 2 == 1 && abs(res[node] - parent) > 1) {
        res[node] ++;
    } 
    if(abs(res[node] - parent) == 2) {
        res[node] ++; res[node] ++;
    }
    val = res[node];
    if(res[node] > vis.size() * 2) {
        cond = false;
    }
    for(ll i : graph[node]) {
        if(!vis[i]) {
            val ++;
            vis[i] = true;
            dfs(graph, i, res[node], res, vis);
        }
    }
}

void sol(){        
    ll n;
    cin >> n;
    val = 1;
    cond = true;
    vector<vector<ll> > g(n);
    ll a, b;
    for(int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        a --; b--;
        g[b].push_back(a);
        g[a].push_back(b);
        
    }
    vector<ll> res(n);
    vector<bool> vis(n, false);
    vis[0] = true;
    dfs(g, 0, 0, res, vis);
    if(!cond) {
        cout << -1 << endl;
        return;
    }
    for(ll i : res) {
        cout << i << ' ';
    }
    cout << endl;
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

