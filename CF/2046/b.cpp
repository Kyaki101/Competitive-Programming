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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll count[26] = {0};
    if(n == 1) {
        cout << s << endl;
        return;
    }
    for(int i = 0; i < n; i++) {

        count[s[i] - 'a'] ++;
    }
    char maxChar, minChar = '-';
    ll maxi = 0, mini = (1 << 30);
    for(int i = 0; i < 26; i++) {
        if(count[i] > maxi) {
            maxChar = (char)(i + 'a');
            maxi = count[i];
        }
    }
    mini = maxi;

    for(int i = 0; i < 26; i++) {
        if(count[i] > 0 && count[i] <= mini && (char)(i + 'a') != maxChar) {
            minChar = (char)(i + 'a');
            mini = count[i];
        }
    }

    if(minChar == '-') {
        minChar = maxChar;
    }
    for(int i = 0; i < n; i++) {
        if(s[i] == minChar) {
            s[i] = maxChar;
            cout << s << endl;
            return;
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

