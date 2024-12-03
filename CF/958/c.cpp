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


typedef unsigned long long int ll;
typedef std::vector<int> vec;
using namespace std;

const int MAX = 2e5+20;
#define int unsigned long long int

int findMSB(unsigned long long number) {
    for(int i = 63; i >= 0; i--){
        if(TEST(number, i)) return i;
    }
    return 0;
}

void sol(){        
    ll n;
    cin >> n;

    if(n == 1 || !(n & (n - 1LL))) {
        cout << "1\n" << n << '\n';
        return;
    }
    int msb = findMSB(n);
    vector<ll> res = {n};
    ll top = n;
    bitset<64> binary(n);

    while(TEST(top, msb)) {
        top = res[res.size() - 1];
        ll next = n;
        int j = 0;
        while(next >= top && j <= 63) {
            if(TEST(top, j)) {
                next = CLEAR(next, j);
            }
            j ++;
        }

        res.push_back(next);
        top = next;
      
    }
    reverse(ALL(res));
    if(res[0] == 0) cout << res.size() - 1LL << '\n';
    else cout << res.size() << '\n';
    for(int i : res) {

        if(i != 0) cout << i << " ";
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

