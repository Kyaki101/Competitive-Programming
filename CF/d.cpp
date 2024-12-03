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


bool cmp(vector<ll> & a, vector<ll> & b) {
    for(int i = 0; i < a.size(); i++) {
        if(a[i] < b[i]) return false;
        if(a[i] > b[i]) return true;
    }
    return true;
}

void sol(){        
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll index = 0, maxi = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] > maxi) {
            maxi = a[i];
            index = i;
        }
    }
    ll sInd = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == maxi - 1) sInd = i;
    }
    if(index != 0) {
        for(int i = index; i < n; i++) {
            cout << a[i] << ' ';
        }
        ll l = 0;
        for(int i = 0; i < index; i++) {
            if(a[i] <= a[index - 1]) {
                l = i;
                break;
            }
        }
        for(int i = index - 1; i >= l; i--) {
            cout << a[i] << ' ';
        }
        for(int i = 0; i < l; i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
        return;
    }

    ll l = 0;
    for(int i = sInd; i < n; i++) {
        cout << a[i] << ' ';
    }

           for(int i = 0; i < sInd; i++) {
            if(a[i] <= a[sInd - 1]) {
                l = i;
                break;
            }
        }
        for(int i = sInd - 1; i >= l; i--) {
            cout << a[i] << ' ';
        }
        for(int i = 0; i < l; i++) {
            cout << a[i] << ' ';
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

