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


ll sum(vector<ll> & a) {
    ll sum = 0;
    for(int i = 0; i < a.size(); i++) {
        sum += a[i];
    }
    return sum;
}

void sol(){        
    ll n;
    cin >> n;
    ll maxi = -(1 << 30);
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> b;
    vector<ll> c;
    while(a.size() > 1) {
        maxi = max(maxi, sum(a));
        for(int i = 0; i < a.size() - 1; i++) {
            c.push_back(a[i + 1] - a[i]);

        }
        reverse(ALL(a));
        for(int i = 0; i < a.size() - 1; i++) {
            b.push_back(a[i + 1] - a[i]);

        }
        maxi = max(sum(b), maxi);
        maxi = max(sum(c), maxi);
        if(sum(c) < sum(b)) {
            a = c;
        }
        else {
            a = b;
        }

        b.clear();
        c.clear();

    }
    maxi = max(sum(a), maxi);
    cout << maxi << endl;
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

