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


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

const int MAX = 2e5+20;

void sol(){        
    int n;
    string s;
    cin >> n >> s;
    if(n == 1) {
        if(s[0] == '1') {
            cout << "YES\n";
            return;
        }
        cout << "NO\n";
        return;
    }
    if(n == 2) {
        if(s[0] == '1' && s[1] == '1') {
            cout << "YES\n";
            return;
        }
        cout << "NO\n";
        return;
    }
    bool found = false;
    int l = 0;
    int r = 0;
    int ones = 0;
    int zeros = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            ones ++;
        }
        if(s[i] == '0' && (i == n - 1 || s[i + 1] == '1')) zeros ++;
    }
    if(ones > zeros) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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

