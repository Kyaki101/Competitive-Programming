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


void comb(vector<vector<ll> > & combs, ll index, vector<ll> & a, vector<ll> current) {
    if(index == a.size()) {
        if(current.size() >= 1) {
            combs.push_back(current);
        }
        return;
    }
    comb(combs, index + 1, a, current);
    current.push_back(a[index]);
    comb(combs, index + 1, a, current);
}


ll lcm(vector<ll> & a, ll n) {
    ll ans = 1;
    for(int i = 0; i < a.size(); i++) {
        if(n / a[i] < ans) {
            return -1;
        }
        ans *= a[i];
    }
    return ans;
}

void sol(){        
    ll n, k;
    cin >> n >> k;
    vector<ll> a(k);
    for(int i = 0; i < k; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    vector<vector<ll> > combs;
    comb(combs, 0, a, {});
    for(vector<ll> i : combs) {
        ll p = lcm(i, n);
        if(p != -1) {
            if(i.size() & 1) {
                ans += n / p;
            }
            else {
                ans -= n / p;
            }
        }

    }
    cout << ans << endl;


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

