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
    vector<ll> b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    set<ll> as;
    set<ll> bs;

    multiset<ll> x;
    multiset<ll> y;

    for(ll i : a) {
        as.insert(i);
        x.insert(i);
    }

    for(ll i : b) {
        bs.insert(i);
        y.insert(i);
    }

    if(bs.size() >= 3) {
        cout << "YES" << endl;
        return;
    }
    if(as.size() >= 3) {
        cout << "YES" << endl;
        return;
    }

    if(as.size() == 2 && bs.size() == 2) {
        ll ab = true;
        ll bb = true;
        for(auto i: as) {
            if(x.count(i) == 1) ab = false;
        }

        for(auto i: bs) {
            if(y.count(i) == 1) ab = false;
        }
        if(ab && bb) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;


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

