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
    stack<pair<ll, ll> > postives;
    stack<pair<ll, ll> > negatives;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > 0) {
            if(negatives.empty()) {
                postives.push({a[i], i});
            }
            else {
                while(!negatives.empty() && abs(negatives.top().first) <= a[i]) {
                    a[i] += negatives.top().first;
                    ans += abs(negatives.top().first) * (i - negatives.top().second);
                    negatives.pop();
                }
                if(!negatives.empty()) {
                    ans += a[i] * (i - negatives.top().second);
                    negatives.top().first += a[i];
                    a[i] = 0;
                }
                else {
                    postives.push({a[i], i});
                }
            }
        }

        else if(a[i] < 0) {
            if(postives.empty()) {
                negatives.push({a[i], i});
            }
            else {
                while(!postives.empty() && postives.top().first <= abs(a[i])) {
                    a[i] += postives.top().first;
                    ans += postives.top().first * (i - postives.top().second);
                    postives.pop();
                }
                if(!postives.empty()) {
                    ans += abs(a[i]) * (i - postives.top().second);
                    postives.top().first += a[i];
                    a[i] = 0;
                }
                else {
                    negatives.push({a[i], i});
                }
            }
        }
    }
    cout << ans << endl;
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

