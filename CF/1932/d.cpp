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

    map<char, vector<ll>> mapa;
    mapa['C'] = vector<ll>(0, 0);
 
    mapa['D'] = vector<ll>(0, 0);
 
    mapa['H'] = vector<ll>(0, 0);
 
    mapa['S'] = vector<ll>(0, 0);
    ll n;
    cin >> n;
    n *= 2;
    char trump;
    cin >> trump;
    for(int i = 0; i < n; i++) {
        string bruh;
        cin >> bruh;
        mapa[bruh[1]].push_back(bruh[0] - '0');
    }
    sort(mapa['C'].begin(), mapa['C'].end());
 
    sort(mapa['D'].begin(), mapa['D'].end());
 
    sort(mapa['H'].begin(), mapa['H'].end());
 
    sort(mapa['S'].begin(), mapa['S'].end());

    ll others = 0;
    for(auto i : mapa) {
        if(i.first != trump && (i.second.size() & 1)) {
            others ++;
        }
    }
    if(others > mapa[trump].size() || (mapa[trump].size() - others) % 2 != 0) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vector<string> res;
    for(auto i : mapa) {
        if(i.second.size() == 1 && i.first != trump) {
            string novo = to_string(i.second[0]) + i.first;
            res.push_back(novo);
        }
        if(i.first != trump && i.second.size() > 1 && i.second.size() % 2 == 1) {
            for(int j = 1; j < i.second.size() - 1; j += 2) {
                cout << i.second[j] << i.first << ' ' << i.second[j + 1] << i.first << endl; 
            }

            string novo = to_string(i.second[0]) + i.first;
            res.push_back(novo);
        }
        else if(i.second.size() > 1 && i.first != trump){
            for(int j = 0; j < i.second.size() - 1; j+= 2) {
                cout << i.second[j] << i.first << ' ' << i.second[j + 1] << i.first << endl; 
            }
        }
    }

    if(res.size() > mapa[trump].size() || (mapa[trump].size() - res.size()) % 2 != 0) {
        cout << "IMPOSSIBLE" << endl; return;
    }
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << ' ' << mapa[trump][i] << trump << endl;
    }
    if(res.size() < mapa[trump].size()) {
        for(int i = res.size(); i < mapa[trump].size() - 1; i += 2) {
            cout << mapa[trump][i] << trump << ' ' << mapa[trump][i + 1] << trump << endl; 
        }
    } 


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

