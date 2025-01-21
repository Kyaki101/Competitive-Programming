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

void sol(){        
    ll n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<vector<ll> > f(n);
    vector<vector<ll> > g(n);
    UnionFind fUF;
    fUF.init(n);
    UnionFind gUF;
    gUF.init(n);
    vector<vector<ll> > fSet(n);
    for(int i = 0; i < m1; i++) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        f[a].push_back(b);
        f[b].push_back(a);
    }

    for(int i = 0; i < m2; i++) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
        gUF.Union(a, b);
    }


    
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        for(ll j : f[i]) {
            if(gUF.Find(i) != gUF.Find(j)) {
                ans ++;
            }
            else {
                fSet[i].push_back(j);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(ll j : fSet[i]) {
            fUF.Union(i, j);
        }
    }
    ans /= 2;

    for(int i = 0; i < n; i++) {
        for(ll j : g[i]) {
            if(fUF.Find(i) != fUF.Find(j)) {
                ans ++;
                fUF.Union(i, j);
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

