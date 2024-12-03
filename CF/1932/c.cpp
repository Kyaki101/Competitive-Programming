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
#define NEUT 1

typedef long long int ll;
long long int MOD;

ll oper(ll a, ll b) {
    return (a * b) % MOD;
}

struct STree { 
    vector<int> st;int n;
    STree(int n): st(4 * n+5,NEUT), n(n) {}
    void init(int k, int s, int e, int *a){
	    if(s+1==e){st[k]=a[s];return;}
	    int m=(s+e)>>1;
	    init(2*k,s,m,a);init(2*k+1,m,e,a);
	    st[k]=oper(st[2*k],st[2*k+1]);
    }

    void upd(int k, int s, int e, int p, int v){
	    if(s+1==e){st[k]=v;return;}
	    int m=(s+e)>>1;
	    (p<m)? upd(2*k,s,m,p,v) : upd(2*k+1,m,e,p,v);
	    st[k]=oper(st[2*k],st[2*k+1]);
    }

    int query(int k, int s, int e, int a, int b){
	    if(s>=b||e<=a)return NEUT;
	    if(s>=a&&e<=b)return st[k];
	    int m=(s+e)>>1;
	    return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
    }

    void init(int *a){init(1,0,n,a);}
    void upd(int p, int v){upd(1,0,n,p,v);}
    int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

const int MAX = 2e5+20;

void sol(){        
    ll n;
    cin >> n >> MOD;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i]; a[i] = a[i] % MOD;
    }
    STree seg(n);
    seg.init(a);
    ll l = 0;
    ll r = n;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++) {
        cout << seg.query(l, r) << " ";
        if(s[i] == 'L') {
            l ++;
        }
        else r--;
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

