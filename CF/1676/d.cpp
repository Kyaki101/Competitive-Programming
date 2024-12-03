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

ll ltoR(ll file, ll column, ll n, ll m, vector<vector<ll>> & a) {
    ll res = 0;
    ll c = column;
    for(int i = file; i < n && c < m; i++) {
        res += a[i][c];
        c++;
    } 

    c = column - 1;
    for(int i = file - 1; i >= 0 && c >= 0; i--) {
        res += a[i][c];
        c--;
    }
    return res;
}

ll rtoL(ll file, ll column, ll n, ll m, vector<vector<ll>> & a) {
    ll res = 0;
    ll c = column - 1;
    for(int i = file + 1; i < n && c >= 0; i++) {
        res += a[i][c];
        c--;
    }
    c = column + 1;
    for(int i = file - 1; i >= 0 && c < m; i--) {
        res += a[i][c];
        c++;
    }
    return res;


}

void sol(){        
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    ll res = 0;
    ll pot = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            pot = 0;
            pot = ltoR(i, j, n, m, a);
            pot += rtoL(i, j, n, m, a);
            res = max(pot, res);

        }

    }
    cout << res << endl;

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

