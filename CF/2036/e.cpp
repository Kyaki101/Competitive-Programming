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
    vector<vector<ll>> regions(n, vector<ll>(m));
    vector<vector<ll>> transpose(m, vector<ll>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> regions[i][j];
            transpose[j][i] = regions[i][j];
        }
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {

            regions[i][j] |= regions[i - 1][j];
            transpose[j][i] = regions[i][j];

        }
    }
    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {
            cout << transpose[j][i] << ' ';
        }
        cout << endl;
    }
    ll reque;

    ll reg;
    ll water;
    char op;
    for(int i = 0; i < q; i++) {
        cin >> reque;
        bool printed = false;
        ll lower = 0;
        ll top = n - 1;
        for(int j = 0; j < reque; j++) {
            cout << lower << ' ' << top << endl;
            cin >> reg >> op >> water;
            ll mid;
            if(op == '>') {
                mid = lower_bound(transpose[reg - 1].begin() + lower, transpose[reg - 1].end() - ((n - 1) - top), water) - transpose[reg - 1].begin();
                if(transpose[reg - 1][mid] == water) {
                    if(mid - 1 < lower) {
                        if(!printed) cout << -1 << endl, printed = true;
                    }
                    else {
                        lower = mid - 1;
                    }
                }
                else
                    lower = mid;
                DEBUG(mid);
                DEBUG("HI");
            }
            else {
                mid = upper_bound(transpose[reg - 1].begin() + lower, transpose[reg - 1].end() - ((n - 1) - top), water) - transpose[reg - 1].begin();
                if(transpose[reg - 1][mid] == water) {
                    if(mid + 1 > top) {
                        if(!printed) cout << -1 << endl, printed = true;
                    }
                    else top = mid + 1;
                }
                else top = mid;
            }

            if(!printed && lower >= top) {
                cout << -1 << endl;
                printed = true;
            }
        }

        if(!printed) cout << lower + 1 << endl;;
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

