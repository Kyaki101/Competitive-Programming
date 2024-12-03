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
#define SET(m, i) ((m) | (1 << (i)))
#define TEST(m, i) ((m) & (1 << (i)))
#define CLEAR(m, i) ((m) &~ (1 << (i)))
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
    string a, b;
    cin >> a >> b;
    string aMod = a;
    string bMod = b;
    for(int i = 0; i < n - 2; i++) {
        if(a[i] == '0' && a[i + 2] == '0') bMod[i + 1] = '1';
    }
    for(int i = 0; i < n - 2; i++) {
        if(bMod[i] == '1' && bMod[i + 2] == '1') aMod[i + 1] = '1';
    }
    vector<int> acumMod(n + 1, 0);
    for(int i = 0; i < n; i++) {
        acumMod[i + 1] = acumMod[i] + (aMod[i] - '0');
    }



    int q;
    cin >> q;
    while(q--) {
        int res = 0;
        int l, r;
        cin >> l >> r;
        if(r - l <= 5) {
            string ap = a;
            string bp = b;
            for(int i = l - 1; i < r - 2; i++) {
                if(a[i] == '0' && a[i + 2] == '0') bp[i + 1] = '1'; 
            }
            for(int i = l - 1; i < r - 2; i++) {
                if(bp[i] == '1' && bp[i + 2] == '1') ap[i + 1] = '1';
            }
            for(int i = l - 1; i < r; i++) {
                if(ap[i] == '1') res ++;
            }
            cout << res << endl;
        }
        else {

       
            res = acumMod[r] - acumMod[l - 1];
            l--;
            r--;
            if(a[l] == '0' && aMod[l] == '1') {
                res --;
            }
            if(a[l + 1] == '0' && aMod[l + 1] == '1' && b[l] == '0') {
                res --;
            }
            if(a[r] == '0' && aMod[r] == '1') {
                res --;
            }
            if(a[r - 1] == '0' && aMod[r - 1] == '1' && b[r] == '0') {
                res --;
            }
            cout << res << '\n';
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

