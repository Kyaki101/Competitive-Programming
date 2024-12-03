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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    map<ll, ll> mapa;
    set<ll> dumb;
    for(int i = 0; i< n; i++) {

        cin >> a[i];
        mapa[a[i]] ++;
        dumb.insert(a[i]);
    }
    vector<ll> bruh;
    for(auto i : dumb) {
        bruh.push_back(i);
    }
    sort(ALL(bruh));
    ll res = 0;
    ll l = 0, r = 1;
    ll p = -1;
    ll maxi = 0;
    ll lr = 0, llo = 0;
    bool ver = false;
         
    bool streak = false;
        
    auto it = mapa.begin();
    while(it != mapa.end()) {
        if(it->second >= k) {
            l = it->first;
            ll w = it->first + 1;
            p = 0;
            while(mapa[w] >= k){w++; p++; it++;}
            if(p >= maxi) {
                maxi = p;
                llo = l;
                lr = w - 1;
            }
            it++;
        }
        else it++;
    }
    if(p == -1) {
        cout << p << endl;
        return;
    }
    cout << llo << ' ' << lr << endl;

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

