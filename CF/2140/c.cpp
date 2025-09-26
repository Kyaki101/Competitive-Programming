#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define F second
#define S first
#define PB push_back
#define ll long long
typedef vector<ll> vll;

const int MAX = 2e5+20, MOD = 1e9+7;

void solve(){        
    ll n;
    cin >> n;
    vector<ll> c(n);
    for(auto &i : c) cin >> i;
    vector<ll> a, b;
    ll bSum = 0, aSum = 0;
    for(int i = 0; i < n; i++) {
        if(i & 1) b.PB(c[i]), bSum += c[i];
        else a.PB(c[i]), aSum += c[i];
    }
    ll wildCard;
    if(n & 1) {
        wildCard += n - 1;
    }
    vector<vector<ll>> dpF(a.size(), vector<ll>(3, 0));
    vector<ll> dpB(a.size(), 0);
    for(int i = 1; i < a.size(); i++) {
        ll x = 

    }


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

