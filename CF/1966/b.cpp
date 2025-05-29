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
const int MAX = 2e5+20, MOD = 1e9+7;

void solve(){        
    ll n, m;
    cin >> n >> m;
    vector<string> mat(n);
    for(auto &i: mat) cin >> i;
    bool down = false, up = false, right = false, left = false;
    for(int i = 0; i < m; i++) {
        if(mat[0][i] == 'W') up = true;
    }
    for(int i = 0; i < m; i++) {
        if(mat[n - 1][i] == 'W') down = true;
    }
    for(int i = 0; i < n; i++) {
        if(mat[i][0] == 'W') left = true;
    }
    for(int i = 0; i < n; i++) {
        if(mat[i][m - 1] == 'W') right = true;
    }
    if(up && down && left && right) {
        cout << "YES" << endl;
        return;
    }
    down = false, up = false, right = false, left = false;
    for(int i = 0; i < m; i++) {
        if(mat[0][i] == 'B') up = true;
    }
    for(int i = 0; i < m; i++) {
        if(mat[n - 1][i] == 'B') down = true;
    }
    for(int i = 0; i < n; i++) {
        if(mat[i][0] == 'B') left = true;
    }
    for(int i = 0; i < n; i++) {
        if(mat[i][m - 1] == 'B') right = true;
    }
    if(up && down && left && right) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

