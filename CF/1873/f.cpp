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

ll bb(vector<ll> & segment, ll startRange, ll l, ll r, ll maxVal) {
    while(r>=l) {
        ll mid = (l + r) / 2;
        if(segment[mid] - segment[startRange - 1] > maxVal) r = mid - 1;
        else l = mid + 1;
    }
    return l - startRange;
}

void sol(){        
    ll n;
    cin >> n;
    ll m;
    cin >> m;
    vector<ll> b(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> acum(n + 1, 0);
    partial_sum(b.begin(), b.end(), acum.begin() + 1);
    ll l = 1;
    ll r = 1;
    ll largest = 0;
    vector<ll> range;
    ll last = a[0];
    for(int i = 1; i < n; i++) {
        if(last % a[i] == 0) {
            r++;
        } 
        else {
            while(l <= r) {
                
                largest = max(largest, bb(acum, l, l, r, m));
                l++;
            }
            l = i + 1;
            r = l;
            
        }
        last = a[i];
    }
    while(l <= r) {

        
        largest = max(largest, bb(acum, l, l, r, m));
        l++;
    }
    cout << largest << endl;
    
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

