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
    string a, b;
    cin >> a >> b;
    ll counter = 0;
    bool streak = a[0] == b[0];
    for(int i = 0; i < max(a.size(), b.size()); i++) {
        if(i < a.size() && i < b.size() && streak && a[i] == b[i]) {
            counter ++;
        }
        if(streak && (a.size() <= i || b.size() <= i || a[i] != b[i])) {
            counter += 2;
            counter += (a.size() > i && b.size() > i);
            streak = false;
        }
        else if(!streak){
            if(i >= a.size()) {
                counter ++;
            }
            if(i >= b.size()) {
                counter ++;
            }
            if(i < b.size() && i < a.size()) {
                counter += 2;
            }
        }

    
    }
    if(streak) {
        cout << counter + 1 << endl;
        return;
    }
    cout << counter << endl;
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

