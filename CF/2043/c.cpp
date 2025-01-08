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
    int index = n;
    bool strange = false;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] != 1 && a[i] != -1) strange = true, index = i;
    }
    ll lemini = 0;
    ll lemaxi = 0;

    ll lowSum = 0;

    ll highSum = 0;
    for(int i = 0; i < index; i++) {
        lowSum = min(0LL, lowSum + a[i]);
        highSum = max(0LL, highSum + a[i]);
        lemini = min(lemini, lowSum);
        lemaxi = max(lemaxi, highSum);

    }
    lowSum = 0; highSum = 0;
    ll rimini = 0;
    ll rimaxi = 0;

    for(int i = index + 1; i < n; i++) {
        lowSum = min(0LL, lowSum + a[i]);
        highSum = max(0LL, highSum + a[i]);
        rimini = min(rimini, lowSum);
        rimaxi = max(rimaxi, highSum);

    }
    set<ll> nums;
    for(ll i = lemini; i <= lemaxi; i++) {
        nums.insert(i);
    }
    for(ll i = rimini; i <= rimaxi; i++) {
        nums.insert(i);
    }
    set<ll> sNums;
    if(strange) {
        ll rMin = 0;
        ll rMax = 0;
        ll sum = 0;
        for(int i = index + 1; i < n; i++) {
            sum += a[i];
            rMin = min(rMin, sum);
            rMax = max(rMax, sum);
        }
        sum = 0;
        ll lMin = 0;
        ll lMax = 0;
        for(int i = index - 1; i >= 0; i--) {
            sum +=a[i];
            lMin = min(lMin, sum);
            lMax = max(lMax, sum);
        }
        for(ll i = lMin + rMin; i <= lMax + rMax; i++) {
            nums.insert(i + a[index]);
        }
        

    }
    cout << nums.size() << endl;
    for(auto i : nums) {
        cout << i << ' ';
    }
    cout << endl;





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

