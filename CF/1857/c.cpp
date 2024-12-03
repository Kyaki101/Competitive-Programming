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
    map<ll, ll> a;
    ll n;
    cin >> n;
    ll num = ((n * (n - 1)) /2);
    vector<ll> bruh(num);
    for(int i = 0; i < num; i++) {
        cin >> bruh[i];
        a[bruh[i]] ++;
    }
    vector<ll> ans;
    ll curr = n - 1;
    for(auto i : a) {
        while(i.second >= curr && i.second > 0) {
            ans.push_back(i.first);
            i.second -= curr;
            curr--;
        } 
    }

    for(int i = ans.size(); i < n; i++) {
        ans.push_back(1000000000);
    }
    for(ll i : ans) {
        cout << i << ' ';
    }
    cout << endl;
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

