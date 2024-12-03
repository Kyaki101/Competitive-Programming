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
    ll x = 0;
    while(s[0] == '0') {
        s.erase(s.begin());
        n--;
    }
    vector<ll> acum(n);
    acum[0] = s[0] - '0';
    ll carry = 0;
    for(int i = 1; i < n; i++) {
        acum[i] = acum[i - 1] + (s[i] - '0'); 
    }
    for(int i = n - 1; i > -1; i--) {
        acum[i] += carry;
        carry = acum[i] / 10;
        if(i != 0) acum[i] = acum[i] % 10;
    }
    for(int i = 0; i < n; i++) {
        cout << acum[i];
    }
    cout << endl;
    
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

