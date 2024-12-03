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
ll mod(ll a, ll b) {
    return ((a % b) + b) % b;
}
void sol(){        
    ll MOD = 1000000007;
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll maxi = 0;
    ll count = 0;
    ll suma = 0;
    for(int i = 0; i < n; i++) {
        count += a[i];
        suma += a[i];
        count = max(count, 0LL);
        maxi = max(count, maxi);
    }
    if(maxi == 0) {
        cout << mod(suma, MOD) << endl;
        return;
    }
    for(int i = 0; i < k; i++) {
        suma = mod(mod(suma, MOD) + mod(maxi, MOD), MOD); 
        maxi = mod(mod(maxi, MOD) * mod(2, MOD), MOD);
    }
    cout << mod(suma, MOD) << endl;
    

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

