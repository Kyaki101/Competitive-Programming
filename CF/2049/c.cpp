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

void sol(){        
    ll n, x, y;
    cin >> n >> x >> y;
    vector<vector<ll> > g(n + 1);
    g[1].push_back(n);
    if(x != y - 1 && x != y + 1 && x != y && !(x == 1 && y == n || x == n && y == 1)) {

        g[x].push_back(y);

        g[y].push_back(x);
    }
    g[n].push_back(1);
    g[n].push_back(n - 1);
    g[1].push_back(2);
    for(int i = 2; i < n; i++) {
        g[i].push_back(i - 1);
        g[i].push_back(i + 1);
    }
    vector<ll> mex(n + 1);
    for(int i = 1; i <= n; i++) {
        mex[i] = g[i].size();
    }

    mex[x] = 0;
    mex[y] = 1;

    for(int i = 1; i <= n; i++) {
        if(i != x && i != y) {

            vector<ll> f;
            for(int j = 0; j < g[i].size(); j++) {
                f.push_back(mex[g[i][j]]);
            }
            ll me = 0;
            sort(ALL(f));
            for(ll j : f) {
                if(j == me) {
                    me++;
                }
            }
            mex[i] = me;

        }
    }
    for(ll i = 1; i <= n; i++) {
        cout << mex[i] << ' ';
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

