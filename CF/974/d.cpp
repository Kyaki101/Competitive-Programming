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
    ll n, d, k;
    cin >> n >> d >> k;
    vector<ll> starts(n + 1, 0);
    vector<ll> ends(n + 1, 0);      
    ll a, b;
    for(int i = 0; i < k; i++) {
        cin >> a >> b;
        ends[a] ++;
        starts[a] ++;
        if(b != n) starts[b + 1] --;

    }
    vector<ll> bac(n + 1, 0);
    for(int i = 1; i < n + 1; i++) bac[i] = bac[i - 1] + starts[i];
    vector<ll> acum(n + 1, 0);
    for(int i = 1; i < n + 1; i++) {
        acum[i] = acum[i - 1] + ends[i];
    }
    ll mini = (1 << 30);
    int mama = 0; int bro = 0;
    ll maxi  = -1;
    ll res = 0;
    for(int i = 1; i <= n - (d - 1); i++) {
        res = 0;
        if(bac[i] != 0) {
            res = bac[i];
        }
        res += acum[i + d - 1] - acum[i];
        if(res < mini) {
            mini = res;
            mama = i;
        }
        if(res > maxi) {
            maxi = res;
            bro = i;
        }
    }
    cout << bro << " " << mama << '\n';

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

