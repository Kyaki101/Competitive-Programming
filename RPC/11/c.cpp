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
    ll C = 0, D = 0, V = 0, L = 0, X = 0, M = 0;
    string s;
    cin >> s;
    ll partial = 0;
    ll totSum = 0;
    for(int i = 0; i < s.size(); i++) {

        if(s[i] == 'I') {
            C ++; D++; V++; L++; X++; M++;
            totSum ++;
        }
        if(s[i] == 'V') {
            C +=5; D +=5; L +=5; X += 5; M += 5;
            totSum = (totSum - V) + (5 - V);
            V = 0;
        }
        if(s[i] == 'X') {
            C += 10; D += 10; L += 10; M += 10;


            totSum = (totSum - X) + (10 - X);
            X = 0;
        }
        if(s[i] == 'L') {
            C += 50; D += 50; M += 50;

            totSum = (totSum - L) + (50 - L);
            L = 0;
        }
        if(s[i] == 'C') {
            D += 100; M += 100;


            totSum = (totSum - C) + (100 - C);
            C = 0;
        }
        if(s[i] == 'D') {
            M += 500;

            totSum = (totSum - D) + (500 - D);
            D = 0;

        }
        if(s[i] == 'M') {

            totSum = (totSum - M) + (1000 - M);
            M = 0;
        }

    }
    cout << totSum << endl;

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

