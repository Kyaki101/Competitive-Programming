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
#define MOD 998244353


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

const int MAX = 2e5+20;

vector<ll> facts(200020, 1);



void fillFactorial() {
    for(int i = 1; i < 200020; i++) {
        facts[i] = ((i % MOD) * (facts[i - 1] % MOD)) % MOD;
    }
}

void sol(){        
    string s;
    cin >> s;
    ll n = s.size();
    ll l = 1;
    char prev = s[0];
    ll streak = 1;
    ll elims = 0;
    ll ways = 1;
    for(int i = 1; i < n; i++) {
        if(s[i] != prev && streak > 1) {
            elims += streak - 1;
            streak = 1;
        }
        else if(s[i] != prev) streak = 1;
        else streak++;
        prev = s[i];
        

    }
    if(streak > 1) {
        elims += streak - 1;
    }
    streak = 1;
    prev = s[0];

    ll perm = facts[elims];

    for(int i = 1; i < n; i++) {
        if(s[i] != prev && streak > 1) {
            ways = ((ways % MOD) * ((streak % MOD) * (perm % MOD) % MOD)) % MOD;

            streak = 1;
        }
        else if(s[i] != prev) streak = 1;
        else streak++;
        prev = s[i];
        

    }
    if(streak > 1) {

        ways = ((ways % MOD) * ((streak % MOD) * (perm % MOD) % MOD)) % MOD;
        streak = 1;
    }


    cout << elims << ' ' << ways << endl;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    fillFactorial();
              
    int t;
    cin >> t;
    while(t--){
        sol();
    }


    return 0;
}

