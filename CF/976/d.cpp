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





class UnionFind {
private: vector<long long int> p, rank, size;
public:
    UnionFind(int n){
        rank.assign(n, 0);
        p.assign(n, 0);
        size.assign(n, 1);
        
        for(long long int i = 0; i < n; i++){
            p[i] = i;
        }
    }
    long long int find(long long int i){
        return (p[i] == i)? i : (p[i] = find(p[i]));
    }

    ll countSets() {
        ll counter = 0;
        for(int i = 0; i < p.size(); i++) {
            if(p[i] == i) counter ++;
        }
        
        return counter;
    }

    bool inSameSet(long long int i, long long int j){
        return find(i) == find(j);
    }
    
    void unionSet(long long int i, long long j){
        if(!inSameSet(i, j)){
            long long int x = find(i), y = find(j);
            if(rank[x] > rank[y] ) {
                p[y] = x;
                size[x] += size[y];
                size[y] = size[x];
                

            }
            else{
                p[x] = y;
                size[y] += size[x];
                size[x] = size[y];
                if(rank[x] == rank[y]) rank[y] ++;
            }
        }
    }
    ll largestSet(){
        ll largest = 0;
        ll index = 0;
        for(int i = 0; i < size.size(); i++){
            if(size[i] > largest){
                index = i;
                largest = size[i];
            }

        }
        return index;
    }



    
};



void sol(){        
    ll n, m;
    cin >> n >> m;
    UnionFind ufds = UnionFind(n); 
    ll a, d, k;
    vector<ll> mults(n, 0);
    for(int i = 0; i < m; i++) {
        cin >> a >> d >> k;
        a--;
        ll j = a;
        ll w = 0;
        ll inc = 1;
        while(w <= k && (mults[j] != 0 && d % mults[j] != 0 || mults[j] == 0) && d != 0) {
            mults[j] = d;
            ufds.unionSet(a, j);
            w += inc;
            j = a + w * d;
        }
        if(w <= k) {
            ufds.unionSet(j, a);
        }


    }
    cout << ufds.countSets() << endl;
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

