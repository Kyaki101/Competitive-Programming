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
    string s;
    cin >> s;
    vector<ll> nums;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') nums.push_back(1);
        else nums.push_back(0);
    }
    vector<ll> acum(n + 1, 0);
    partial_sum(ALL(nums), acum.begin() + 1);
    ll ans = 0;
    ll i = 0;
    ll carry = 0;
    while(i <= n) {
        if(acum[i] - acum[max(i - (k + 1), 0LL)] == 0 && acum[min(n, i + k)] - acum[i] == 0 && s[i - 1] == '0') {
            s[i - 1] = '1';
            ans ++;
            i += k + 1;
        }
        else i++;
    }
    DEBUG(ans);
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
