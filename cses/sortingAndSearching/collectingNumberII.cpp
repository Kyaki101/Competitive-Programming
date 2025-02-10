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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    map<ll, ll> mapa;
    mapa[0] = (-1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        mapa[a[i]] = i;
    }
    ll ans = 1;
    for(int i = 1; i <= n; i++) {
        if(mapa[a[i] - 1] > mapa[a[i]]) {
            ans ++;
        }
    }
    cout << ans << endl;

    ll x, y;
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        if(abs(a[x] - a[y]) == 1) {
            if(a[y] > a[x]) {
                ans ++;
            }
            else {
                ans --;
            }
            cout << a[x] << ' ' << a[y] << endl;
            cout << ans << endl;
            swap(a[x], a[y]);
            continue;
        }
        bool xGood = true;
        bool yGood = true;
        bool xG = true;
        bool yG = true;
        if(mapa[a[x]] < mapa[a[x] - 1]) {
            xGood = false;
        }

        if(mapa[a[y]] < mapa[a[y] - 1]) {
            yGood = false;
        }

        if(mapa[a[x] + 1] < mapa[a[x]] && a[y] != n) {
            xG = false;
        }

        if(mapa[a[y] + 1] < mapa[a[y]] && a[y] != n) {
            yG = false;
        }

        mapa[a[x]] = y;
        mapa[a[y]] = x;

        if(xGood && mapa[a[x]] < mapa[a[x] - 1]) {
            ans ++;
        }
        else if(!xGood && mapa[a[x]] > mapa[a[x] - 1]) {
            ans --;
        }

        if(yGood && mapa[a[y]] < mapa[a[y] - 1]) {
            ans ++;
        }
        else if(!yGood && mapa[a[y]] > mapa[a[y] - 1]) {
            ans --;
        }

        if(mapa[a[x] + 1] < mapa[a[x]] && xG && a[x] != n) {
            ans ++;
        }

        if(mapa[a[y] + 1] < mapa[a[y]] && yG && a[x] != n) {
            ans ++;
        }

        if(mapa[a[x] + 1] > mapa[a[x]] && !xG && a[x] != n) {
            ans --;
        }

        if(mapa[a[y] + 1] > mapa[a[y]] && !yG && a[y] != n) {
            ans --;
        }

        swap(a[x], a[y]);

        cout << ans << endl;

        


    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

              
    int t;
    t = 1;
    while(t--){
        sol();
    }


    return 0;
}

