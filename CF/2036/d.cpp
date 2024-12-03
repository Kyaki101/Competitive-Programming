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


ll travelLayer(ll i, ll j, int n, int m, vector<string> & mat) {
    string f = "1543";
    ll index = 0;
    ll count = 0;
    for(int k = j; k < m - j - 1; k++) {
        if(mat[i][k] == f[index]) {
            if(index == 3) {
                count ++;
                index = 0;
            }
            else index ++;
        } 
        else if(mat[i][k] == '1') {
            index = 1;
        }
        else index = 0;

    }
    ll x = m - j - 1;
    for(int k = i; k < n - i - 1; k++) {
        if(mat[k][x] == f[index]) {
            if(index == 3) {
                count ++;
                index = 0;
            }
            else index ++;
        }
        else if(mat[k][x] == '1') {
            index = 1;
        }
        else index = 0;
    }

    ll y = n - i - 1;
    for(ll k = x; k > j; k--) {
        if(mat[y][k] == f[index]) {
            if(index == 3) {
                count ++;
                index = 0;
            }
            else index ++;
        }
        else if(mat[y][k] == '1') {
            index = 1;
        }
        else index = 0;
    }



    for(int k = y; k > i; k--) {

         if(mat[k][j] == f[index]) {
            if(index == 3) {
                count ++;
                index = 0;
            }
            else index ++;
        }       
        else if(mat[k][j] == '1') {
            index = 1;
        }
        else {
            index = 0;
        }
    }







    ll passed = 0;
    for(int k = j; k < m - j - 1; k++) {
        if(mat[i][k] == f[index] && passed < 4 && index != 0) {

            if(index == 3) {
                count ++;
                index = 0;
            }
            else index ++;
        } 
        else {
            return count;
        }
        passed ++;

    }

    x = m - j - 1;
    for(int k = i; k < n - i - 1; k++) {
        if(mat[k][x] == f[index] && passed < 4 && index != 0) {
            if(index == 3) {
                count ++;
                index = 0;
            }
            else index ++;
        }
        else {
            return count;
        }
        passed ++;
    }
    y = n - i - 1;
    for(ll k = x; k > j; k--) {
        if(mat[y][k] == f[index] && passed < 4 && index != 0) {
            if(index == 3) {
                count ++;
                index = 0;
            }
            else index ++;
        }
        else {
            return count;
        }
        passed ++;
    }
    for(int k = y; k > i; k--) {
         if(mat[k][j] == f[index] && passed < 4 && index != 0) {
            if(index == 3) {
                count ++;
                index = 0;
            }
            else index ++;
        }       
        else {
            return count;
        }
        passed ++;
    }

    return count;
}

void sol(){        
    ll n, m;
    cin >> n >> m;
    vector<string> mat(n);
    for(int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    ll i = 0;
    ll j = 0;
    ll count = 0;
    while(i < n / 2 && j < m / 2) {
        count += travelLayer(i, j, n, m, mat); 
        i++; j++;
    }
    cout << count << endl;
    
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

