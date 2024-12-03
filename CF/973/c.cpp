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
    int n;
    cin >> n;
    string s = "";
    bool found = false;
    bool toRight = true;
    bool first = true;
    if(n == 1) {
        int res;
        cout << "? 1" << endl;
        cin >> res;
        if(res) {
            cout << "! 1" << endl;
            return;
        }
        else {
            cout << "! 0\n" << endl;
            return;
        }
    }
    while(!found) {
        int res;
        if(first) {
            cout << "? 01" << endl; 
            cin >> res;
            if(res) s = "01";
            else {
                cout << "? 10" << endl;
                cin >> res;
                if(res) s = "10";
                else {
                    string neve = "";
                    for(int i = 0; i < n; i++) neve += '1';
                    cout << "? " << neve << endl;
                    cin >> res;
                    if(res) {
                        cout << "! " << neve << endl;
                        cout.flush();
                    }
                    else {
                        neve = "";
                        for(int i = 0; i < n; i++) {
                            neve += '0';
                        }
                        cout << "! " << neve << endl;
                        cout.flush();
                    }
                    return;
                }
            }
            first = false;
            if(n == 2) {
                cout << "! " << s << endl;
                cout.flush();
                return;
            }
        }
        if(toRight) {
            cout << "? " << s + '1' << endl;
            cin >> res;
            if(res == 1) s = s + '1';
            else {
                if(!first) {
                    cout << "? " << s + '0' << endl;
                    cin >> res;
                    if(res == 1) s = s + '0';
                    else toRight = false;
                }
            }
        } 
        if(!toRight) {
            cout << "? " << '1' + s << endl;
            cin >> res;
            if(res == 1) s = '1' + s;
            else {
                s = '0' + s;
            }
        }
        if(s.size() == n) found = true;
    }
    cout << "! " << s << endl;
    cout.flush();
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

