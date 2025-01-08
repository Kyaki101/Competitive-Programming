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

ll res;
ll iters;




void nQueens(vector<ll> pos, ll index, vector<string> & board) {
    if(index == 8) {
        res ++;
        return;
    }
    for(int i = 0; i < 8; i++) {
        vector<ll> cpy = pos;
        cpy[index] = i;
        bool valid = true;
        for(int j = 0; j < index; j++) {
            if(cpy[index] == cpy[j] || abs(index - j) == abs(cpy[index] - cpy[j])) {
                valid = false;
            }
        }
        if(valid && board[index][cpy[index]] != '*') {
            nQueens(cpy, index + 1, board);
        }
    }


}



void sol(){        
    vector<string> board(8);
    iters = 0;
    res = 0;
    for(int i = 0; i < 8; i++) {
        cin >> board[i];
    }

    vector<ll> pos(8);
    nQueens(pos, 0, board);
    cout << res << endl;

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

