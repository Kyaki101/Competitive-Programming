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
    
    string s;
    cin >> s;
    ll n = s.size();
    char reserve;
    string a = "";
    string b = "";
    map<char, ll> mapa;
    for(int i = 0; i < n; i++) {
        mapa[s[i]] ++;
    }
    bool check = false;
    for(auto i : mapa) {
        if(i.second & 1 && n % 2 == 0 || check && i.second & 1) {
            cout << "NO SOLUTION"<< endl;
            return;
        }
        if(i.second & 1 && n & 1 && !check) {
            check = true;
            reserve = i.first;
            i.second --;
        }
        while(i.second) {
            if(i.second & 1) a.push_back(i.first);
            else b.push_back(i.first);
            i.second --;
        }
        
    }
    if(check) {
        b.push_back(reserve);
    }
    reverse(ALL(b));
    cout << a << b << endl;
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

