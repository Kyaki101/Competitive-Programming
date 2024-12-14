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
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] --;
    }
    vector<pair<pair<ll, ll>, pair<ll, ll> > > ans(k, {{-1, -1}, {-1, -1}});
    set<ll> tops;
    vector<ll> visSide(k, -1);
    vector<ll> visTops(k, -1);
    for(int i = 0; i < n; i++) {
        tops.insert(a[i]);
        if(visTops[a[i]] < 0) {
            ll f = a[i];
            while(f > -1 && visTops[f] == -1) {
                visTops[f] = i;
                f--;
            }
        }
        
    }
    for(int i = n - 1; i > -1; i--) {
        if(visSide[a[i]] < 0) {
            ll f = a[i];
            while(f > -1 && visSide[f] == -1) {
                visSide[f] = i;
                f--;
            }
        }
    }

    for(int i = 0; i < k; i++) {
        ans[i].first.first = visTops[i];
        ans[i].second.first = visTops[i];
        ans[i].first.second = visSide[i];
        ans[i].second.second = visSide[i];
    }
    ll m = 0;
    for(auto i : ans) {
        if(tops.find(m) != tops.end()) {
            cout << (i.first.second - i.first.first + 1) + (i.second.second - i.second.first + 1) << ' ';
        }
        else cout << 0 << ' ';
        m ++;
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

