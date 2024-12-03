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

int moves[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};


ll dfs(ll i, ll j, vector<vector<bool>> & vis, vector<vector<ll>> & mat, ll val) {
    val = mat[i][j];

    for(int k = 0; k < 4; k++) {
        if(moves[k][0] + i >= 0 && moves[k][1] + j >= 0 && moves[k][0] + i < vis.size() && moves[k][1] + j < vis[0].size() && mat[moves[k][0] + i][moves[k][1] + j] != 0) {
            if(!vis[i + moves[k][0]][j + moves[k][1]]) {
                vis[i + moves[k][0]][j + moves[k][1]] = true;
                val += dfs(i + moves[k][0], j + moves[k][1], vis, mat, val);
            }

        }
    }
    return val;
}

void sol(){        
    ll n, m;
    cin >> n >> m;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<ll>> mat(n, vector<ll>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    ll maxi = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && mat[i][j] != 0) {
                vis[i][j] = true;
                maxi = max(dfs(i, j, vis, mat, 0), maxi);
            }
        }
    }
    cout << maxi << endl;



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

