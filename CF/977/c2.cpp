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
    ll n, m, q;
    cin >> n >> m >> q;
    vector<ll> a(n);
    vector<ll> pos(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];

        pos[a[i]] = i;
    }
    vector<ll> b(m);
    bitset<m + 1> problems;
    ll p = 0;
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }



    set<ll> visited;
    vector<ll> dp(m + 1, 0);
    visited.insert(b[0]);
    for(int i = 0; i < m; i++) {
        if(pos[b[i]] > visited.size()) {
            problems.set(i);
            p++;
            dp[i] = visited.size();
        } 
        else {

            dp[i] = visited.size();
            visited.insert(b[i]);
        }
    }
    if(p) {
        cout << "TIDAK" << endl;
    }
    else cout << "YA" << endl;
    for(int i = 0; i < q; i++) {
        ll posi, num;
        cin >> posi >> num;
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

