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

ll expo(ll n, ll x, ll MOD) {
    if(!x) return 1;
    if(x & 1) {
        return ((n % MOD) * (expo(n, x - 1, MOD) % MOD)) % MOD;
    }
    ll y = expo(n, x / 2, MOD);
    return ((y % MOD) * (y % MOD)) % MOD;
}

void sol(){        
    ll n, a, b;
    cin >> n >> a >> b;
    if(b == 0) {
        cout << n << endl;
        return;
    }
    if(a == 0) {
        cout << 1 << endl;
        return;
    }
    ll y = expo(n, expo(a, b, 1000000006), 1000000007);
    cout << y << endl;

    
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

