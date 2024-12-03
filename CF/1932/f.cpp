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
    ll n, m;
    cin >> n >> m;
    vector<ll> op(n + 1, 0);
    vector<vector<ll>> end(n + 1);
    ll a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        op[a] ++;
        end[b].push_back(a);
    }
    vector<ll> dp(n + 1);
    multiset<ll> curr;
    for(int i = 1; i <=n; i++) {
        dp[i] = dp[i - 1];
        for(int j = 0; j < op[i]; j++) {
            curr.insert(i);
        }
        if(!curr.empty()) {
            dp[i] = max(dp[i], (ll) (dp[*curr.begin() - 1] + curr.size()));
        }
        for(ll x : end[i]) {
            curr.erase(curr.find(x));
        }
    }
    cout << dp[n] << endl;

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

