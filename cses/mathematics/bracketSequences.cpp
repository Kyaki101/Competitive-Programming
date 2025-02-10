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
#define MOD 1000000007


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

const int MAX = 2e5+20;

ll expo(ll n, ll x) {
    if(x == 0) return 1;
    if(x & 1) return ((n % MOD) * (expo(n, x - 1) % MOD)) % MOD;
    ll y = expo(n, x / 2);
    return ((y % MOD) * (y % MOD)) % MOD;
}

ll factorial(ll n) {
    if(n == 0) return 1;
    return ((n % MOD) * (factorial(n - 1) % MOD)) % MOD;
}


ll choose(ll a, ll b) {
    ll top = factorial(a);
    ll bottom = factorial(b);
    bottom = ((bottom % MOD) * (factorial(a - b) % MOD)) % MOD;
    return ((top % MOD) * (expo(bottom, MOD - 2) % MOD)) % MOD;
}

void sol(){        
    ll n;
    cin >> n;
    if(n & 1) {
        cout << 0 << endl;
        return;
    }
    ll ch = choose(n, n / 2);
    ll ans = ((ch % MOD) * (expo((n / 2) + 1, MOD - 2) % MOD)) % MOD;
    cout << ans << endl;
    return;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

              
    int t;
    t = 1;
    while(t--){
        sol();
    }


    return 0;
}

