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
    string s;
    cin >> s;
    if(s[0] - '0' >= 5) {
        cout << 1;
        for(int i = 0; i < s.size(); i++) {
            cout << 0;
        }
        cout << endl;
        return;
    }
    string res; 
    res.push_back(s[0]);
    for(int i = 1; i < s.size(); i++) {
        if(s[i] - '0' >= 5) {
            ll j = i - 1;
            bool found = false;
            while(j >= 0) {
                if(res[j] != '9') {
                    res[j] ++;
                    found = true;
                    break;
                }
                else j--;
            }
            if(!found) {
                cout << 1;
                for(int k = 0; k < s.size(); k++) {
                    cout << 0;
                }
                cout << endl;
                return;
            }
            else {

                for(int k = 0; k <= j; k++) {
                    cout << res[k];
                } 
                for(int k = j + 1; k < s.size(); k++) {
                    cout << 0;
                }
                cout << endl;
                return;
            }
        }
        else res.push_back(s[i]);
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

