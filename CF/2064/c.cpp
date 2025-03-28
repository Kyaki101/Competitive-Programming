#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
typedef long long int ll;
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

void solve(){        
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> acumPos(n + 1, 0);
    vector<ll> acumNeg(n + 1, 0);
    for(int i = 0; i < n; i++) {
        if(a[i] > 0) {
            acumPos[i + 1] = acumPos[i] + a[i];
            acumNeg[i + 1] = acumNeg[i];
        }
        else {
            acumNeg[i + 1] = acumNeg[i] + abs(a[i]);
            acumPos[i + 1] = acumPos[i];
        }
    }
    ll maxi = 0;
    for(int i = 0; i < n; i++) {
        maxi = max(maxi, acumPos[i + 1] + (acumNeg[n] - acumNeg[i]));
    }
    cout << maxi << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

