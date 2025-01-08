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

struct UnionFind{
    vector<int> uf;
    void init(int n){uf.assign(n, -1);}
    int Find(int i){return (uf[i]==-1)? i : uf[i] = Find(uf[i]);}
    bool Union(int i, int j){
        bool e = Find(i)==Find(j);
        if(!e) uf[Find(i)] = Find(j);
        return e;
    }
};

ll dp(vector<ll> & memo, ll index, vector<ll> & a, ll i, ll steps, UnionFind & uf) {
    uf.Union(index, i);
    if(i == index) {
        memo[i] = steps;
        return memo[i];
    }
    memo[i] = dp(memo, index, a, a[i], steps + 1, uf);
    return memo[i];

}

void sol(){        
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    UnionFind uf;
    uf.init(n + 1);
    vector<ll> memo(n + 1, -1);
    for(int i = 1; i <= n; i++) {
        if(a[i] == i) memo[i] = 1;
        else if(memo[i] == -1){
            dp(memo, i, a, a[i], 1, uf);
        }
    }
    ll ans = 0;

    vector<ll> diffs;

    std::priority_queue<int, std::vector<int>, std::greater<int> > minHeap;

    for(int i = 1; i <= n; i++) {
        if(uf.Find(i) == i) {
            minHeap.push(memo[i]);
        }
    }
    while(minHeap.size() > 1) {
        ll q = minHeap.top();
        minHeap.pop();
        ll p = minHeap.top();
        minHeap.pop();
        ans += p + q;
        minHeap.push(p + q);
    }


    cout << ans;

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

