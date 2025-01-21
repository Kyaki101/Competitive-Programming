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
    map<ll, ll> mapa;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mapa[a[i]] ++;
    }
    ll legs = 0;
    bool l = false;
    for(auto i : mapa) {
        if(i.first > legs && i.second >= 2) {
            legs = i.first;
            l = true;
        }
    }
    if(!l) {
        cout << -1 << endl;
        return;
    }
    mapa[legs] -= 2;
    sort(ALL(a));
    ll found = true;
    bool upF = false;
    bool downF = false;
    vector<ll> c;
    for(auto i : mapa) {
        while(i.second > 0) {
            i.second --;
            c.push_back(i.first);
        }
    }
    sort(ALL(c));
    ll diff = (1 << 30);
    ll up, down;
    for(int i = 0; i < c.size() - 1; i++) {
        if(c[i + 1] - c[i] < diff) {
            diff = c[i + 1] - c[i];
            up = c[i];
            down = c[i + 1];
        }

    }
    double minSize = (down - up * 1.0) / 2.0;
    if(legs <= minSize) {
        cout << -1 << endl;
        return;
    }
    cout << legs << ' ' << legs << ' '<< up << ' ' << down << endl;

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

