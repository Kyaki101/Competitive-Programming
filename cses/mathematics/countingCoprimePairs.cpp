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


void combinations(vector<vector<ll> > & combs, vector<ll> & a, ll index, vector<ll> current) {
    if(index == a.size()) {
        if(current.size() >= 1) {
            combs.push_back(current);
        }
        return;
    }
    combinations(combs, a, index + 1, current);
    current.push_back(a[index]);
    combinations(combs, a, index + 1, current);
}

ll listProd(vector<ll> & a) {
    ll prod = 1;
    for(int i = 0; i < a.size(); i++) {
        prod *= a[i];
    }
    return prod;
}


ll choose2(ll n) {
    return (n * (n - 1)) / 2;
}

void sol(){        
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> mapa;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mapa[a[i]] ++;
    }
    vector<vector<ll> > divisors(1000001);
    for(int i = 2; i < 1000001; i++) {
        if(divisors[i].size() == 0) {
            for(int j = i; j < 1000001; j+=i) {
                divisors[j].push_back(i);
            }
        }
    }

    vector<ll> mobius(1000001, 1);
    vector<ll> primeCount(1000001, 0);
    vector<bool> vis(1000001, 0);
    for(int i = 0; i < n; i++) {
        if(!vis[a[i]]) {
            vis[a[i]] = true;
            vector<vector<ll> > combs;
            combinations(combs, divisors[a[i]], 0, {});
            for(vector<ll> j : combs) {
                ll prod = listProd(j);
                if(j.size() & 1) {
                    mobius[prod] = 1;
                }
                else mobius[prod] = -1;
                primeCount[prod] += mapa[a[i]];
            }
        }
    }
    ll ans = choose2(n);
    ll tog = 0;

    for(int i = 0; i < 1000001; i++) {
        if(primeCount[i] > 1) {
            tog += choose2(primeCount[i]) * mobius[i];
        }
    }

    cout << ans - tog << endl;
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

