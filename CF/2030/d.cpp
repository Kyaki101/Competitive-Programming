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
    for(int i = 0 ; i < n; i++) {
        cin >> a[i];
        a[i] --;
    }
    string s;
    cin >> s;
    vector<ll> diff(n);
    vector<ll> inv(n);
    for(int i = 0; i < n; i++) {
        inv[a[i]] = i;
    }
    for(ll i = 0; i < n; i++) {
        diff[min(i, inv[i])] ++;
        diff[max(i, inv[i])] --;
    }
    partial_sum(ALL(diff), diff.begin());
    set<ll> bad;
    for(ll i = 0; i < n - 1; i++) {
        if(s[i] == 'L' && s[i + 1] == 'R' && diff[i] != 0) {
            bad.insert(i);
        }
    }
    for(ll i = 0; i < q; i++) {
        ll b;
        cin >> b;
        b--;
        if(s[b] == 'L') s[b] = 'R';
        else s[b] = 'L';
        if(bad.find(b) != bad.end()) {
            bad.erase(b);
        }
        if(bad.find(b - 1) != bad.end()) {
            bad.erase(b - 1);
        }
        if(s[b] == 'L' && s[b + 1] == 'R' && diff[b] != 0) {
            bad.insert(b);
        }
        if(s[b] == 'R' && s[b - 1] == 'L' && diff[b - 1] != 0) {
            bad.insert(b - 1);
        }
        if(bad.size() == 0) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }


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

