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


ll f(vector<ll> & a, ll n) {
    ll ans = 0;
    for(int i = 0; i < a.size(); i++) {
        ans += a[i] * n;
        n --;
    } 
    return ans;
}

ll g(vector<ll> & a, ll n) {
    ll ans = 0;
    for(int i = 0; i < a.size(); i++) {
        ans += a[i] * n;
        n ++;
    }
    return ans;
}

void sol(){        
    ll n, m;
    cin >> n >> m;

    vector<vector<ll> > a(n, vector<ll>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    std::sort(ALL(a), [&](vector<ll> & c, vector<ll> & b) {
        ll fa = f(c, m);
        ll fb = f(b, m);
        ll s1 = 0;
        ll s2 = 0;
        for(int i = 0; i < m; i++) {
            s1 += c[i];
            s2 += b[i];
        }
        if(s1 != s2) {
            return s1 > s2;
        }
        return fa > fb;
    });
    ll ans = 0;
    ll scalar = n * m;
    for(int i = 0; i < n; i++) {
        ans += f(a[i], scalar);
        scalar -= m;
    }
    cout << ans << endl;


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

