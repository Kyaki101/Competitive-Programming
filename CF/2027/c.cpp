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
    vector<ll> a(n + 1);
    for(int i = 1; i < n + 1; i++) {
        cin >> a[i];
    }
    vector<ll> b(n, 0);
    if(n == 1) {
        cout << "1\n"; return;
    }
    map<ll, ll> man;
    map<ll, vector<ll>> nums;
    for(int i = 2; i <= n; i++) {
        if(a[i] - (n + 1 - i) >= 0) {
            nums[a[i] - (n + 1 - i)].push_back(i - 1);
            man[a[i] - (n + 1 - i)] ++;
        }
    }
    for(auto it=nums.rbegin(); it != nums.rend(); it++) {
        ll maxi = 0;
        for(ll j : it->second) {
            if(nums.find(j + it->first) != nums.end()) {
                maxi = max(maxi, j + man[it->first + j]);
                
            }  
            else {
                maxi = max(maxi, j);
            }
            
        }
        man[it->first] = maxi;
    }
    cout << n + man[0] << endl;;





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

