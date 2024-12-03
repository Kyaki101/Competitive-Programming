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


ll logarithm(ll base, ll num) {
    ll res = 0;
    while(num != 0) {
        num /= base;
        if(num != 0) res ++;
    }
    return res;
}

void sol(){        
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool maxi = 0;
    long double lmaxi = 0;
    ll count = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > 1) maxi = true;
        if(maxi && a[i] == 1) {
            cout  << "-1\n";
            return;
        }
        long double lo = log2(a[i]);
        
        if(lo < lmaxi) {
            cout << lmaxi << ' ' << lo << endl;
            ll diff = ceil(log2(lmaxi - lo));
            if(diff < 1) {
                lo *= 2;
                count ++;
            }
            else {

                count += diff;

                lo = diff * (2 * lo);
            }
        }
        lmaxi = lo;


    }
    cout << count << endl;
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

