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


bool powerOf2(ll n) {
    return !(n & (n - 1));
}


ll msb(ll n) {
    ll ans = 0;
    for(int i = 0; i < 60; i++) {
        if(TEST(n, i)) ans = i;


    }
    return ans;
}


void solve(){        
    ll a;
    cin >> a;
    if(powerOf2(a) || (1LL << (msb(a) + 1)) - 1 == a) {
        cout << -1 << endl;
        return;
    }

    cout << (1LL << msb(a)) -1 << endl;


}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

