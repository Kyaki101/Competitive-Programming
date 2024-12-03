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

ll b[MAX];

void sol(){        
    ll n, x;
    for(int i = 0; i < MAX; i++) b[i] = 0;
    cin >> n >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(ALL(a));
    if(a[0] != 0) {
        cout << 0 << endl;
        return;
    }
    ll prev = 0;
    ll i = 1;
    ll expected = 1;
    while(i < n) {

        if(a[i] == prev) {
            b[prev % x] ++;
            i++;
        }
        else if(a[i] == expected) {
            prev ++;
            expected ++;
            i++;
        }

        else if(b[(expected) % x]) {

            b[(expected) % x] --;
            prev ++;
            expected ++;

        }
        else {
                cout << expected << endl;
                return;
        }
        
        
        
    }
    ll res = prev + 1;
    while(b[res % x] && res <= MAX - 20) {
        b[(res) % x] --;
        res ++;

    }
    cout << res << endl;

    
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

