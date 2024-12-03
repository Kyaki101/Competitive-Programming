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

ll findMin(vector<ll> & a) {
    ll mini = (1LL << 60);
    for(int i = 0; i < a.size(); i++) {
        mini = min(mini, a[i]);
    }
    return mini;



}

void sol(){        
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll count = 0;
    vector<ll> segment;
    sort(a.rbegin(), a.rend());
    for(int i = 0; i < min(x, n); i++) {
        segment.push_back(a[i]);
    }
    ll bruh = min(x, n);
    ll res = 0;
    while(segment.size() != 0) {
        ll mini = findMin(segment);

        res += mini;

        for(int i = 0; i < segment.size(); i++) {
            segment[i] -= mini;
        }
        for(int i = 0; i < segment.size(); i++) {
            if(segment[i] == 0) {
                segment.erase(segment.begin() + i);
                if(bruh < n) {
                    segment.push_back(a[bruh]);
                    bruh++;
                }
            }
        }
    }
    cout << res << endl;







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

