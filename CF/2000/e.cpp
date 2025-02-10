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
    ll n, m, k;
    cin >> n >> m >> k;
    ll w;
    cin >> w;
    vector<ll> a(w);
    for(int i = 0; i < w; i++) {
        cin >> a[i];
    }
    vector<ll> ans;
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
            ll horizontal = 0;
            ll vert = 0;
            if(i <= k) {
                horizontal = min(i, n - k + 1);
            }
            else if(i > k) {
                horizontal = min(n - i + 1, k);
            }

            if(j <= k) {
                vert = min(j, m - k + 1);
            }
            else {
                vert = min(m - j + 1, k);
            }

            ans.push_back(vert * horizontal);

            
        }
    }
    sort(ans.rbegin(), ans.rend());
    sort(a.rbegin(), a.rend());
    ll res = 0;

    for(int i = 0; i < w; i++) {
        res += a[i] * ans[i];
    }
    cout << res<< endl;

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

