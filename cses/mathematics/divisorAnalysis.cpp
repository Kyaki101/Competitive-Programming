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
using namespace std;

const int MAX = 2e5+20;

ll expo(ll n, ll x) {
    if(x == 0) return 1LL;
    if(x & 1) return ((n % MOD) * (expo(n, x - 1) % MOD)) % MOD;
    ll y = expo(n, x / 2) % MOD;
    return ((y % MOD) * (y % MOD)) % MOD;
}


ll modInverse(ll n) {
    return expo(n, MOD - 2);
}


ll powerSum(ll n, ll k) {
    ll upper = ((expo(n, k + 1) % MOD) - (1 % MOD) + MOD) % MOD;
    ll calc = ((n % MOD) - (1 % MOD) + MOD) % MOD;
    ll down = modInverse(calc);
    ll ans = ((upper % MOD) * (down % MOD)) % MOD;
    return ans;

}

void sol(){        
    ll n;
    cin >> n;
    vector<pair<ll, ll> > factors(n);
    ll a, b;
    ll factsEnum = 1;
    ll count = 0;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        factors[i].first = a;
        factors[i].second = b;
        count += factors[i].second;
        factsEnum = ((factsEnum % MOD) * ((factors[i].second + 1) % MOD)) % MOD;
    }

    ll factsProd = 1;
    ll bruh = 1;
    for(int i = 0; i < n; i++) {
        ll gauss = (((factors[i].second * (factors[i].second + 1)) / 2)) % (MOD - 1);
        gauss = ((gauss % (MOD - 1)) * (bruh % (MOD - 1)) % (MOD - 1));
        factsProd = ((expo(factsProd, factors[i].second + 1) % MOD) * (expo(factors[i].first, gauss) % MOD)) % MOD;
        bruh = bruh * (factors[i].second + 1) % (MOD - 1);
    }
    ll factsSum = 1;
    ll totSum = factsSum;

    for(int i = 0; i < n; i++) {
        factsSum = ((factsSum % MOD) * (powerSum(factors[i].first, factors[i].second) % MOD)) % MOD;

    }
    cout << factsEnum << ' ';
    cout << factsSum  << ' ';
    cout << factsProd << endl;





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

