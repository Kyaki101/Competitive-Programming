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
    ll n;
    cin >> n;
    ll sum = 0;
    vector<ll> a(n);
    for(int i = 0 ;i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if(n == 1) {
        cout << "YES\n";
        return;
    }


    ll needed = 0;
    for(int i = n - 1; i > -1; i--) {

        if(a[i] - (sum / n) > needed) {
            cout << "NO\n";
            return;
        }
        if(a[i] < (sum / n)) needed += (sum / n) - a[i];
        else {
            needed -= a[i] - (sum / n);
        }
    }
    if(needed != 0) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

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

