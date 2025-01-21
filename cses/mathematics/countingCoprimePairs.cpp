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
    map<ll, ll> mapa;
    ll maxi = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mapa[a[i]] ++;
        maxi = max(a[i], maxi);
    }
    vector<ll> twins(maxi + 1, 0);
    vector<ll> mults(maxi + 1, 0);
    vector<bool> sieve(maxi + 1, false);
    sieve[0] = true;
    sieve[1] = true;
    for(int i = 2; i <= maxi; i++) {
        if(!sieve[i]) {
            if(mapa.find(i) != mapa.end()) {
                mults[i] += mapa[i];
            }
            for(int j = i * 2; j <= maxi; j += i) {
                sieve[j] = true;
                if(mapa.find(j) != mapa.end()) mults[i] += mapa[j];
            }

        }
    }

    for(int i = 2; i <= maxi; i++) {
        if(!sieve[i]) {
            if(mapa.find(i) != mapa.end()) {
                twins[i] = mults[i];
            }
            for(int j = i * 2; j <= maxi; j+= i) {
                if(mapa.find(j) != mapa.end()) twins[j] += (mults[i] - mapa[i]);
            }
        }
    }
    ll ans = 0;
    ll na = n;
    if(mapa.find(1) != mapa.end()) {
        for(int i = 0; i < mapa[1]; i++) {
            ans += na;
            na --;
        }
        n -= mapa[1];
    }

    for(int i = 2; i < maxi + 1 && n > 0; i++) {
        if(twins[i] != 0) {
            cout << i << ": " << twins[i] << endl;
            if((n - (twins[i] + mapa[i])) * mapa[i] > 0) ans += (n - (twins[i] + mapa[i])) * mapa[i], n -= mapa[i];
        }
    }
    cout << ans << endl;



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

