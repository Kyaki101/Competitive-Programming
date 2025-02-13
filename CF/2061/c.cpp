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
#define MOD 998244353

typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

const int MAX = 2e5+20;

void sol(){        
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<bool> liars(n, false);
    ll l = 0;
    if(a[0] > 0) {
        liars[0] = true;
        l = 1;
    }
    for(int i = 1; i < n; i++) {
        if(a[i] > (i + 1) / 2 || a[i] < l) {
            liars[i] = true;
            l ++;
        }
        if(liars[i] && liars[i - 1]) {
            cout << 0 << endl;
            return;
        }
    }
    vector<ll> dp(n, 0);
    if(a[0] == 0) {
        dp[0] = 1;
    }
    if(a[1] == 0 || a[1] == 1) {
        dp[1] = 1;
    }
    for(int i = 2; i < n; i++) {
        if(a[i] == a[i - 1]) {
            dp[i] += dp[i - 1] % MOD;
            dp[i] % MOD;
        }

        if(a[i - 2] + 1 == a[i]) dp[i] += dp[i - 2] % MOD, dp[i] % MOD;

    }

    if(n == 1) {
        cout << dp[0] + 1 << endl;
        return;
    }


    cout << (dp[n - 1] + dp[n - 2]) % MOD << endl;
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

