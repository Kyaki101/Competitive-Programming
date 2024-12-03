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


int contains(string & s, ll n) {
    if(n - 3 >= 0) {
        if(s[n - 3] == '1' && s[n - 2] == '1' && s[n - 1] == '0' && s[n] == '0') return n;
    }
    if(n - 2 >= 0 && n + 1 < s.size()) {
        if(s[n - 2] == '1' && s[n - 1] == '1' && s[n] == '0' && s[n + 1] == '0') return n + 1;
    }
    if(n - 1 >= 0 && n + 2 < s.size()) {
        if(s[n - 1] == '1' && s[n] == '1' && s[n + 1] == '0' && s[n + 2] == '0') return n + 2;
    }
    if(n + 3 < s.size()) {
        if(s[n] == '1' && s[n + 1] == '1' && s[n + 2] == '0' && s[n + 3] == '0') return n + 3;
    }
    return 0;
}

void sol(){        
    string s;
    cin >> s;
    ll q;
    ll ini = 0;
    ll k = 0;
    while(k < s.size()) {
        int bruh = contains(s, k); 
        if(bruh) {
            ini ++;
            k = bruh + 1;
        }
        else k++;
            
    }
    cin >> q;
    for(int i = 0; i < q; i++) {
        int a;
        char c;
        cin >> a >> c;
        a--;
        if(contains(s, a)) {
            s[a] = c;
            if(!contains(s, a)) {
                ini --;
            }
        }
        else {
            s[a] = c;
            if(contains(s, a)) {
                ini ++;
            }
        }
        if(ini > 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

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

