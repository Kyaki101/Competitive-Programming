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
    vector<vector<ll> > a(n, vector<ll>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }


    for(vector<ll> & i : a) {
        reverse(ALL(i));
    }

    vector<ll> acums(n);


    for(int i = 0; i < n; i++) {
        ll j = 0;
        ll ans = 0;
        while(a[i][j] == 1 && j < n) {
            ans ++;
            j++;
        }
        if(ans == 0) {
            acums[i] = -1;
        }
        else {
            acums[i] = ans;
        }
    }

    sort(ALL(acums)); 

    ll index = 0;
    while(acums[index] == -1 && index < n) {
        index ++;
    }

    ll finding = 1;
    for(int i = index; i < n; i++) {

        if(acums[i] >= finding) {
            finding ++;
        }
    }

    if(finding == n + 1) {
        cout << n << endl;
        return;
    }
    cout << finding << endl;

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

