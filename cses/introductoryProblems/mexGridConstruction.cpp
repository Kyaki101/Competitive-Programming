#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define pb push_back
#define ll long long
#define ml __int128
const int MAX = 2e5+20, MOD = 1e9+7;
const int bitSize = 200;


ll findNxt(bitset<bitSize> & a, bitset<bitSize> & b) {
    for(int i = 0; i < bitSize; i++) {
        if(!a.test(i) && !b.test(i)) {
            return i;
        }
    }
    return 0;
}


void solve(){        
    ll n;
    cin >> n;
    vector<bitset<bitSize>> rows(n, 0);
    vector<bitset<bitSize>> columns(n, 0);
    vector<vector<ll>> mat(n, vector<ll>(n));
    for(int i = 0; i < n; i++) {
        mat[i][0] = i;
        rows[i].set(i);
    }
    for(int i = 0; i < n; i++) {
        mat[0][i] = i;
        columns[i].set(i);
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            ll nxt = findNxt(rows[i], columns[j]);
            columns[j].set(nxt);
            rows[i].set(nxt);
            mat[i][j] = nxt;
        }
    }
    for(auto i : mat) {
        for(auto j : i) cout << j << ' ';
        cout << endl;
    }

    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

