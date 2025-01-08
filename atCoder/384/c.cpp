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


void genPerm(ll index, string & a, string res, vector<string> & combinations) {
    if(index == a.size()) {
        if(res.size() != 0) {
            combinations.push_back(res);
        }
        return;
    }
    
    string bruh = res;
    bruh += a[index];
    genPerm(index + 1, a, bruh, combinations);
    genPerm(index + 1, a, res, combinations);
}


void sol(){        
    ll a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    string f = "ABCDE";

    map<ll, vector<string>> mapa;
    map<char, ll> vals;
    vals['A'] = a;
    vals['B'] = b;
    vals['C'] = c;
    vals['D'] = d;
    vals['E'] = e;

    vector<string> combs;
    string q = "";
    genPerm(0, f, q, combs);
    sort(ALL(combs));
    for(int i = 0; i < 31; i++) {
        ll score = 0;
        for(int j = 0; j < combs[i].size(); j++) {
            score += vals[combs[i][j]];
        }
        mapa[score].push_back(combs[i]);
    }

    vector<string> res;

    for(auto i : mapa) {
        sort(i.second.rbegin(), i.second.rend());
        for(auto j : i.second) {
            res.push_back(j);
        }
        
    }

    for(int i = 30; i > -1; i--) {
        cout << res[i] << endl;
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

