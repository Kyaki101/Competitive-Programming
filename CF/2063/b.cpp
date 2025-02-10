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
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    l --;
    r --;
    ll leftSum = 0;
    vector<ll> left;
    for(int i = 0; i <= r; i++) {
        left.push_back(a[i]);
    }
    sort(ALL(left));
    for(int i = 0; i < r - l + 1; i++) {
        leftSum += left[i];
    }
    ll rightSum = 0;
    vector<ll> right;
    for(int i = l; i < n; i++) {
        right.push_back(a[i]);
    }
    sort(ALL(right));
    for(int i = 0; i < r - l + 1; i++) {
        rightSum += right[i];
    }
    cout << min(rightSum, leftSum) << endl;
    return;
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

