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


void insertHeap(vector<ll> & heap, ll n) {
    heap.push_back(n);
    if(heap.size() == 1) return;
    ll pos = heap.size() - 1;
    while(pos != 0 && heap[pos] < heap[(pos - 1) / 2]) {
        swap(heap[pos], heap[(pos - 1) / 2]);
        pos = (pos - 1) / 2;
    }
}

void sol(){        
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    multiset<ll, greater<ll> > ava;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ava.insert(a[i]);
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < m; i++) {
        if(ava.lower_bound(b[i]) == ava.end()) {
            cout << -1 << endl;
        }
        else {
            cout << *ava.lower_bound(b[i]) << endl;
            ava.erase(ava.lower_bound(b[i]));
        }
    }



}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

              
    int t;
    t = 1;
    while(t--){
        sol();
    }


    return 0;
}

