#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<'\n'
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define ll long long
const int MAX = 1e4+20, MOD = 1e9+7;
int t=1, n, k, a[MAX], b[MAX], dp[MAX][MAX];

int OPT(int i, int j){
    if(i==n*k || j==n*k) return 0;
    int &cur = dp[i][j];
    if(cur!=-1) return cur;
    if(a[i]==b[j]) return cur = 1+OPT(i+1, j+1);
    return cur = max(OPT(i+1, j), OPT(i, j+1));
}

void solve(){        
    cin>>n>>k;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i<n*k; ++i) cin>>a[i];
    for(int i = 0; i<n*k; ++i) cin>>b[i];
    cout<<OPT(0, 0)<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    while(t--){
        solve();
    }return 0;
}

