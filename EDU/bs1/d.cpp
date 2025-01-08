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
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(ALL(a));
    ll q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        ll c, b;
        cin >> c >> b;
        ll l = -1, r = n;
        while(r > l + 1) {
            ll m = (l + r) / 2;
            if(a[m] < c) l = m;
            else r = m;
        }
        ll e = r + 1;
        l = -1; r = n;
        while(r > l + 1) {
            ll m = (l + r) / 2;
            if(a[m] <= b) l = m;
            else r = m;
        }
        if(e - 1 < n && a[e - 1] < c || l > -1 && a[l] > b) {
            cout << 0 << ' ';
            return;
        }
        ll f = l + 1;
        cout << min(f - e + 1, n) << ' ';
    }
    cout << endl;
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

