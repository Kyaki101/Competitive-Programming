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

ll dfs(ll node, vector<vector<ll>> & graph, vector<ll> & values, ll level, bool odd, vector<bool> & vis) {
    vis[node] = true;
    ll res = 0;
    if(odd){
        if(level & 1) {
            res += values[node];
        }
    } 
    else {
        if(!(level & 1)) {
            res += values[node];
        }
    }
    for(int i = 0; i < graph[node].size(); i++) {
        if(!vis[graph[node][i]]) res += dfs(graph[node][i], graph, values, level + 1, odd, vis);
    }
    return res;
}

void sol(){        
    int n;
    cin >> n;
    vector<ll> g(n);
    for(int i = 0; i < n; i++) cin >> g[i];
    vector<vector<ll>> graph(n);
    vector<bool> vis(n, false);
    ll a, b;
    for(int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        a --; b --;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    ll odds = dfs(0, graph, g, 0, 1, vis);
    vis.assign(n, false);
    ll evens = dfs(0, graph, g, 0, 0, vis);
    cout << (max(odds, evens) + min(odds, evens) * 2) << '\n';
    
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

