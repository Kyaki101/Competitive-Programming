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
    vector<ll> diff(n + 1, 0);
    for(int i = 0; i < m; i++) {
        vector<ll> bruh;
        ll x, y;
        cin >> x >> y;
        ll k = 0;
        for(int j = 1; j <= n; j++) {
            ll d;
            cin >> d;
            if(d == 1) {
                k ++;
                bruh.push_back(j);
            }
            else diff[j] += y;
        }
        if(x / (k + 1) >= y) {
            diff[0] += x / (k + 1);
            for(auto b : bruh) diff[b] += x / (k + 1);
        }
        else {
            diff[0] += y;
            for(auto b : bruh) diff[b] += x / (k);
        } 
    }
    for(int i = 1; i <= n; i++) cout << diff[i] << ' ';
    cout << diff[0];
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

