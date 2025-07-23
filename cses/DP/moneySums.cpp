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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    ll maxi = 100002;
    vector<bool> dp(maxi, false);
    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = maxi - 1; j >= a[i]; j--) {
            if(j - a[i] >= 0 && dp[j - a[i]]) {
                dp[j] = 1;
            } 
        }
    }
    ll count = 0;
    for(int i = 1; i < maxi; i++) {
        if(dp[i]) count ++;
    }
    cout << count << endl;
    for(int i = 1; i < maxi; i++) {
        if(dp[i]) cout << i << ' ';
    }
    cout << endl;
    

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

