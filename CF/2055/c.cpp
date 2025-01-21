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
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<ll> F(n, 0);
    vector<vector<ll> > mat(n, vector<ll>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
            F[i] += mat[i][j];
        }
    }


    vector<ll> C(m, 0);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            C[i] += mat[j][i];
        }
    }

    ll starter;
    if(s[0] == 'D') {
        starter = -F[0];

    }

    else {
        starter = -C[0];
    }

    mat[0][0] = starter;
    C[0] += starter;
    F[0] += starter;
    ll goal;
    if(s[0] == 'D') {
        goal = F[0];
        
    }
    else goal = C[0];
    
    ll x = s[0] == 'D';
    ll y = s[0] == 'R';
    for(int i = 1; i < s.size(); i++) {

        if(s[i] == 'D') {
            mat[x][y] = goal - F[x];
            F[x] += mat[x][y];
            C[y] += mat[x][y];
            x ++;
        }

        else {
            mat[x][y] = goal - C[y];
            F[x] += mat[x][y];
            C[y] += mat[x][y];           
            y++;
        }
    }

    mat[n - 1][m - 1] = goal - F[n - 1];



    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
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

