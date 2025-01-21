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
    vector<ll> a(5);
    cin >> a[0] >> a[1] >> a[3] >> a[4];
    a[2] = a[0] + a[1];
    bool might = true;
    for(int i = 0; i < 5; i++) {
        if(a[i] != 0) might = false;
    }
    if(might) {
        cout << 3 << endl;
        return;
    }
    ll ans = 1;
   
    for(int i = 3; i < 5; i++) {
        if(a[i] == a[i - 1] + a[i -2]) {
            ans ++;
        }

    }
    if(a[1] - a[3] == a[3] - a[4]) {
        cout << max(ans, 2LL) << endl;
        return;
    }
    if(a[3] == a[4]) {
        cout << max(2LL, ans) << endl;
        return;
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

