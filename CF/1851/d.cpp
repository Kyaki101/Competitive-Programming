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
    vector<ll> a(n - 1);

    multiset<ll> weird;
    for(int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }
    vector<ll> norm(n - 1);
    norm[0] = a[0];
    weird.insert(norm[0]);
    for(int i = 1; i < n - 1; i++) {
        norm[i] = abs(a[i] - a[i - 1]);
        weird.insert(norm[i]);
    }
    sort(ALL(norm));
    multiset<ll> nums;
    for(int i = 1; i <= n; i++) {
        nums.insert(i);
        if(weird.count(i)) weird.erase(weird.find(i));

    }

    
    ll oddOne = *weird.begin();
    for(ll i : norm) {
        if(nums.find(i) != nums.end()) nums.erase(i);
    }
    if(nums.size() > 2) {
        cout << "NO" << endl;
        return;
    }
    if(nums.size() == 1) {
        cout << "YES" << endl;
        return;
    }
    vector<ll> rest;
    for(int i : nums) {
        rest.push_back(i);
    }
    if(rest[0] + rest[1] == oddOne) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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

