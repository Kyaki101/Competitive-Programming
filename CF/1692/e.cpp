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
    ll n, k;
    cin >> n >> k;
    ll sum = 0;
    vector<short int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if(k > sum) {
        cout << -1 << endl;
        return;
    }
    ll i = 0; 
    ll j = n - 1;
    queue<ll> lefts;
    queue<ll> rights;
    ll moves = 0;
    for(int i = 0; i < n; i++) {
        if(a[i]) lefts.push(i);
    }
    for(int i = n - 1; i >= 0; i --) {
        if(a[i]) rights.push(i);
    }
    while(sum != k) {
        if(lefts.front() - i == j - rights.front()) {
            sum --;
            moves += lefts.front() - i + 1;
            i = lefts.front() + 1;
            lefts.pop();
            if(sum == k) {
                cout << moves << endl;
                return;
            }
            if(j - rights.front() <= lefts.front() - i) {
                sum --;
                moves += j - rights.front() + 1;
                j = rights.front() - 1;
                rights.pop();
            }

        }
        else if(lefts.front() - i <= j - rights.front()) {
            moves += lefts.front() - i + 1;
            i = lefts.front() + 1;
            lefts.pop();

            sum --;
        }
        else {
            moves += j - rights.front() + 1;
            j = rights.front() - 1;
            rights.pop();
            sum --;
        }
    }
    cout << moves << endl;

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

