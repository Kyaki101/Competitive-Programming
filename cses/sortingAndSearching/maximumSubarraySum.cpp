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
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll maxi = 0;
    ll curr = 0;
    bool bruh = false;
    for(int i = 0; i < n; i++) {
        if(a[i] >= 0) {
            bruh = true;
        }
    }
    if(!bruh) {

        ll maxi2 = (1LL << 60);
        for(int i = 0; i < n; i++) {
            maxi2 = min(maxi2, abs(a[i]));

        }
        cout << -1LL * maxi2 << endl;
        return;
    }

    for(int i = 0; i < n; i++) {
        curr = max(0LL, curr + a[i]);
        maxi = max(maxi, curr);
    }
    cout << maxi << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

              
    int t;
    t = 1;
    while(t--){
        sol();
    }


    return 0;
}

