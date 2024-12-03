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
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<ll, ll> mapa;

    for(int i = 0; i < n - 1; i++) {
        ll val = (i + 1) * (n - i) - 1;
        if(mapa.find(val) == mapa.end()) {
            mapa[val] = 1;
        }
        else mapa[val] ++;
        ll middle = (i + 1) * (n - (i + 1));
        if(mapa.find(middle) == mapa.end()) {
            mapa[middle] = a[i + 1] - a[i] - 1;
        }
        else mapa[middle] += a[i + 1] - a[i] - 1;

    }
    mapa[n - 1] ++;
    for(int i = 0; i < q; i++) {
        ll b;
        cin >> b;
        if(mapa.find(b) == mapa.end()) {
            cout << "0 ";
        }
        else cout << mapa[b] << " ";
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

