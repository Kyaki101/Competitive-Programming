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
#define SET(m, i) ((m) | (1 << (i)))
#define TEST(m, i) ((m) & (1 << (i)))
#define CLEAR(m, i) ((m) &~ (1 << (i)))
#define DEBUG(n) (cout << (n) << endl)
#define CLEAN(arr) (memset(arr, 0, sizeof(arr)))
#define ALL(v) (v).begin(), (v).end()
#define int long long int

typedef std::vector<int> vec;
using namespace std;

const int MAX = 2e5+20;

void sol(){        
    int n, k;
    cin >> n >> k;
    vec a(n);
    int maxi = -1;
    int index = 0;
    int trailing = 0;
    int acum = k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] > maxi) {
            maxi = a[i];
            index = i;
        }
    }
    for(int i  = 0; i < n; i++) {
        if(a[i] < maxi) {
            if(a[i] + acum >= maxi) {
                cout << trailing << " ";
            }
            else cout << trailing + 1 << " ";
        }
        else {
            if(a[i] <= a[0] + k) {
                cout << trailing << " ";
            }
            else if(i == index) {
                cout << "0 ";
            }
            else cout << trailing << " ";
        }
        trailing ++;
        acum += a[i];
    }
    cout << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

              
    int t;
    cin >> t;
    while(t--){
        sol();
    }


    return 0;
}

