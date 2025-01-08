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


ll moves[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

map<ll, char> mv;

ll iters = 0;


ll exits(ll i, ll j, vector<vector<bool> > & grid) {
    ll count = 0;
    for(int k = 0; k < 4; k++) {
        count += moves[k][0] + i > -1 && i + moves[k][0] < 7 && moves[k][1] + j > -1 && moves[k][1] + j < 7 && grid[i + moves[k][0]][j + moves[k][1]] == 0;
    }
    return count;
    
}

bool valid(ll i, ll j, vector<vector<bool> > & grid) {
    return i > -1 && i < 7 && j > -1 && j < 7 && grid[i][j] == 0;
}

void pathFinder(ll i, ll j, vector<vector<bool> > board, string path, vector<string> & paths) {
    board[i][j] = true;
    if(path.size() > 40)cout << path << ' ' << path.size() << endl;
    if(i == 6 && j == 0) {
        if(path.size() == 48) cout << path << endl;
        return;
    }

    int oneCount = 0;
    ll fi;
    ll fj;
    char m;
    for(int k = 0; k < 4; k++) {
        if(valid(i + moves[k][0], j + moves[k][1], board)) {
        ll ex = exits(i + moves[k][0], j + moves[k][1], board);
            if(ex == 1) {
                oneCount ++;
                fi = i + moves[k][0];
                fj = j + moves[k][1];
                m = mv[k];
                
            } 
            if(ex == 0 && !(i + moves[k][0] == 6 && moves[k][1] + j == 0)) {
                return;
            }
        }
    }
    if(oneCount > 1) {
        return;
    }
    if(oneCount == 1) {
        pathFinder(fi, fj, board, path + m, paths);
        return;
    }
    for(int k = 0; k < 4; k++) {
        if(valid(i + moves[k][0], j + moves[k][1], board)) {
            pathFinder(i + moves[k][0], j + moves[k][1], board, path + mv[k], paths);
        }
    }



}

void sol(){        
    string s;
    cin >> s;
    mv[0] = 'U';
    mv[1] = 'L';
    mv[2] = 'D';
    mv[3] - 'R';
               
    vector<vector<bool> > grid(7, vector<bool>(7, false));

    grid[0][0] = true;
    string k = "";
    vector<string> paths;

    pathFinder(0, 0, grid, k, paths);
    cout << paths.size() << endl;

    
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

