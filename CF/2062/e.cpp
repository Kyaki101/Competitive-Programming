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

ll dfs(vector<vector<ll> > & g, vector<ll> & w, vector<ll> & maxis, ll node, vector<bool> & vis) {
    ll maxi = w[node];
    vis[node] = true;
    for(int i = 0; i < g[node].size(); i++) {
        if(!vis[g[node][i]]) {
            maxi = max(maxi, dfs(g, w, maxis, g[node][i], vis));
        }
    }
    maxis[node] = maxi;
    return maxi;

}

void sol(){        
    ll n;
    cin >> n;
    vector<ll> w(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    vector<vector<ll> > g(n + 1);
    for(int i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<bool> vis(n + 1, false);
    vector<ll> maxis(n + 1, 0);
    dfs(g, w, maxis, 1, vis);
    vector<pair<ll, ll> > mex;
    for(int i = 1; i <= n; i++) {
        mex.push_back({maxis[i], i});
    }
    sort(mex.rbegin(), mex.rend());
    for(int i = 0; i < mex.size(); i++) {
        if(mex[i].first != mex[0].first) {
            cout << mex[i].second << endl;
            return;
        }
    }

    cout << 0 << endl;
    return;


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

