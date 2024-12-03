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

void setSize(vector<vector<ll>> & tree, ll node, vector<ll> & memo) {
    ll size = 1;
    for(int i = 0; i < tree[node].size(); i++) {
        setSize(tree, tree[node][i], memo);
        size += memo[tree[node][i]];
    }
    memo[node] = size;
}

ll components = 0;

ll poss(vector<vector<ll>> & tree, ll x, ll node, ll k, vector<ll> memo) {
    ll loss = 0;
    for(int i = 0; i < tree[node].size(); i++) {
        loss += poss(tree, x, tree[node][i], k, memo);
    }
    memo[node] -= loss;

    if(memo[node] >= x) {
        components ++;
        return memo[node];
    }
    return 0;
}

ll bb(ll ini, ll fin, ll k, vector<vector<ll>> & tree, vector<ll> & memo) {
    if(fin <= ini) return ini;
    ll mid = (ini + fin) / 2;
    if(mid == ini)
    components = 0;
    poss(tree, mid, 1, k, memo);
    if(components >= k + 1) {
        return bb(mid + 1, fin, k, tree, memo);
    }
    return bb(ini, mid - 1, k, tree, memo);
    
    
}

void sol(){        
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> tree(n + 1);
    for(int i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        tree[a].push_back(b);
    }
    vector<ll> memo(n + 1);
    setSize(tree, 1, memo);
    ll co = bb(1, n - 1, k, tree, memo);
    components = 0;
    poss(tree, co, 1, k, memo);
    if(components >= k + 1) {
        cout << co << endl;
        return;
    }
    cout << co - 1 << endl;


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

