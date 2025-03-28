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
    ll x;
    cin >> x;
    vector<ll> acum(32, 0);
    acum[0] = 1;
    acum[1] = 2;
    for(int i = 2; i < 32; i++) {
        acum[i] = acum[i - 2] + (1LL << i);
    }
    vector<ll> ans(32, 0);
    ll num = 0;
    ll index = 0;
    for(int i = 0; i > 32; i++) {
        if(acum[i] > x) {
            ans[i] = 1;
            index = i;
            break;
        }


    }



}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

