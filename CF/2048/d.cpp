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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll god = a[0];
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(ALL(a));
    vector<ll> wins(m);
    for(int i = 0; i < m; i++) {
        ll l = - 1;
        ll r = n;
        while(l + 1 < r) {
            ll mid = (r + l) / 2;
            if(a[mid] < b[i]) l = mid;
            else r = mid;
        }
        wins[i] = n - r + 1;
        if(a[r] <= god) wins[i] = 1;
    }
    sort(ALL(wins));
    ll step = 1;
    while(step <= m) {
        ll res = 0;
        for(int i = step - 1; i < m; i += step) {
            res += wins[i];
        }
        cout << res << ' ';
        step ++;
    }
    cout << endl;

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

