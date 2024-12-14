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
    ll n, k;
    cin >> n >> k;
    ll power = (1LL << (n - 1));
    if(power < k && n <= 60) {
        cout << "-1" << endl;
        return;
    }
    vector<ll> a, b;
    k --;
    vector<ll> d;
    while(k) {
        d.push_back(k % 2);
        k /= 2;
    }
    while(d.size() < n - 1) d.push_back(0);

    for(ll i = n - 2, j = 1; i >= 0; i --, j++) {
        if(d[i] == 0) a.push_back(j);
        else b.push_back(j);
    }
    reverse(ALL(b));
    for(ll i : a) cout << i << ' ';
    cout << n << ' ';
    for(ll i : b) cout << i << ' ';
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

