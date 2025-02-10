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

void sol(){        
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll k = s.size();
    if(n & 1) {
        cout << 0 << endl;
        return;
    }
    ll o = 0;
    ll c = 0;
    ll diff = 0;
    for(int i = 0; i < k; i++) {
        if(s[i] == '(') {
            o ++;
            diff ++;
        }
        else {
            c ++;
            diff --;
        }
        if(diff < 0) {
            cout << 0 << endl;
            return;
        }
    }
    if(diff > n - k) {
        cout << 0 << endl;
        return;
    }
    if(k == n) {
        cout << 1 << endl;
        return;
    }
    if(diff == (n - k)) {
        cout << 1 << endl;
        return;
    }
    ll rc = diff;
    ll ro = 0;
    ro = ((n - k) - diff) / 2;
    rc += ro;
    vector<ll> facts(1000001, 0);
    facts[1] = 1;
    facts[0] = 1;
    for(int i = 2; i < 1000001; i++) {
        facts[i] = ((i % MOD) * (facts[i - 1] % MOD)) % MOD;
    }
    ll top = facts[n - k];
    ll bottom = facts[rc];
    bottom = ((bottom % MOD) * (facts[(n - k) - rc] % MOD)) % MOD;
    ll comb = ((top % MOD) * (expo(bottom, MOD - 2) % MOD)) % MOD;
    bottom = facts[rc + 1];
    bottom = ((bottom % MOD) * (facts[(n - k) - (rc + 1)] % MOD)) % MOD;
    ll subtr = ((top % MOD) * (expo(bottom, MOD - 2) % MOD)) % MOD;
    ll ans = ((comb % MOD) - (subtr % MOD) + MOD) % MOD;
    cout << ans << endl;
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

