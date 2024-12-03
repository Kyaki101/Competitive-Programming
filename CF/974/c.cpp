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


ll bs(ll size, ll mid, ll sum,  ll low, ll high) { 
    ll m = (low + high) / 2;
    if(low == high) {
        return high;
    }
    if(mid < (sum + m) / (size * 2.0)) {
        return bs(size, mid, sum, low, m);
    }
    return bs(size, mid, sum, m + 1, high);
    
    return 1;

}

void sol(){        
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(ALL(a));
    ll mid;
    if(n == 1 || n == 2) {
        cout << "-1\n";
        return;
    }
    mid = a[n / 2];
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
    }
    if(mid < 1.0 * sum / (n * 2.0)) {
        cout << "0\n";
        return;
    }
    cout << bs(n, mid, sum, 0, 1000000000000LL) << endl;
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

