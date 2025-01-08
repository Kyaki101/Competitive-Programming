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


bool valid(ll i, ll j, vector<vector<bool> > & board) {
    return i > -1 && i < 7 && j > -1 && j < 7 && board[i][j] == false;
}

ll exits(ll i, ll j, vector<vector<bool> > & board) {
    ll res = 0;
    for(int k = 0; k < 4; k++) {
        if(valid(i + moves[k][0], j + moves[k][1], board)) {
            res ++;
        }
    }
    return res;
}

map<ll, char> mapa;
ll iters = 0;

void pathFinder(ll i, ll j, vector<vector<bool> > & board, vector<string> & res, string & path) {
    iters ++;
    board[i][j] = true;
    if(i == 6 && j == 0) {
        if(path.size() == 48) {
            res.push_back(path);
        }
        board[i][j] = false;
        return;
    }
    if(!valid(i + 1, j, board) && !valid(i - 1, j, board) && valid(i, j + 1, board) && valid(i, j - 1, board)) {
        board[i][j] = false;
        return;
    }
    if(!valid(i, j - 1, board) && !valid(i, j + 1, board) && valid(i + 1, j, board) && valid(i - 1, j, board)) {
        board[i][j] = false;
        return;
    }

    bool oner = false;
    ll fx, fy;

    char mv;
    for(int k = 0; k < 4; k++) {
        ll fi =  i + moves[k][0];
        ll fj = j + moves[k][1];
        if(valid(fi, fj, board)) {
            if(exits(fi, fj, board) == 1 && oner && !(fi == 6 && fj == 0)) {
                board[i][j] = false;
                return;
            }
            if(exits(fi, fj, board) == 1 && !(fi == 6 && fj == 0)) {
                fx = fi; fy = fj;
                oner = true;
                mv = mapa[k];
            }
        }

    }
    if(oner) {
        path.push_back(mv);
        pathFinder(fx, fy, board, res, path);
        path.pop_back();
        board[i][j] = false;
        return;
    }

    for(int k = 0; k < 4; k++) {
        ll fi = i + moves[k][0];
        ll fj = j + moves[k][1];
        if(valid(fi, fj, board)) {
            path.push_back(mapa[k]);
            pathFinder(fi, fj, board, res, path);
            path.pop_back();
        }

    }
    board[i][j] = false;


    
}

void sol(){        

    string s;
    cin >> s;
    mapa[0] = 'U';
    mapa[1] = 'L';
    mapa[2] = 'D';
    mapa[3] = 'R';
    string path = "";
    vector<string> res;
    vector<vector<bool> > grid(7, vector<bool>(7, false));
    pathFinder(0LL, 0LL, grid, res, path);
    ll count = 0;
    for(string & i : res) {
        bool valid = true;
        for(int j = 0; j < 48; j++) {
            if(s[j] != '?' && s[j] != i[j]) {
                valid = false;
            }
        }
        if(valid) count ++;

    }
    cout << count << endl;
    
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

