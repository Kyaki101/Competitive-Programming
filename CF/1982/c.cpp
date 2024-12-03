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


ll bb(ll l, ll r, vector<ll> & acum, ll maxi, ll index) {
    if((r + l) / 2 == l) return l;
    ll mid = (l + r) / 2;
    if(acum[index] - acum[mid - 1] > maxi) return bb(mid + 1, r, acum, maxi, index);
    return(l, mid, acum, maxi, index);
        
    
}

void sol(){        
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll count = 0;
    vector<ll> acum(n + 1, 0);
    partial_sum(ALL(a), acum.begin() + 1);
    ll ini = 1;

    for(int i = 1; i <= n; i++) {
        ll curr = acum[i] - acum[ini - 1];
        if(curr >= l && curr <= r) {
            count ++;
            ini = i + 1;
        }
        else if(curr > r) {
            ll b = bb(ini, i, acum, r, i);
            if(acum[i] - acum[b - 1] >= l && acum[i] - acum[b - 1] <= r) {
                count ++;
                ini = i + 1;
            }
            else {
                ini = b;
            }
           
        }
    }
    cout << count << endl;

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

