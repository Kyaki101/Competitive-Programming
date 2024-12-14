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

ll gauss(ll n) {
    return (n * (n + 1)) / 2;
}

ll bb(ll lower, ll upper, ll target) {

    ll mid = (lower + upper) / 2;
    if(lower >= upper) {
        return mid;
    }
    if(gauss(mid) == target) {
        return mid;
    }
    if(gauss(mid) > target && gauss(mid - 1) < target) {
        return mid;
    }
    if(gauss(mid) < target) {
        return bb(mid + 1, upper, target);
    }
    return bb(lower, mid - 1, target);

    
}

ll fixedGauss(ll n, ll top) {
    ll k = top + 1;
    return ((k * (k + 1)) / 2) + (top * (top + 1)) / 2 - (n * (n - 1)) / 2;
}

ll higherBB(ll lower, ll upper, ll target, ll highest) {
    ll mid = (lower + upper) / 2; 
    if(lower <= upper) {
        return mid;
    }
    if(fixedGauss(mid, highest) == target) return mid;
    if(fixedGauss(mid, highest) > target && fixedGauss(mid + 1, highest) < target) return mid;
    if(fixedGauss(mid, highest) < target) return higherBB(mid - 1, upper, target, highest);
    return higherBB(lower, mid + 1, target, highest);
}

void sol(){        
    ll k, m;
    cin >> k >> m;
    ll full = (k * (k + 1)) / 2 + ((k * (k + 1)) / 2) - k;
    ll half = (k * (k + 1)) / 2;
    if(m > full) {
        cout << 2 * k - 1 << endl;;
        return;
    }

    if(m <= half) {
        cout << bb(1, k, m) << endl;
        return;
    }
    cout << k + (k - higherBB(k - 1, 1, m, k - 1)) << endl;



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

