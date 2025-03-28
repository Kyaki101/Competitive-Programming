#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define MOD 1000000007
typedef long long int ll;
const int MAX = 2e5+20; 
int t=1;


ll div2(ll n) {
    ll ans = 0;
    while(n % 2 == 0) {
        n /= 2;
        ans++;
    }

    return ans;

}


ll expoLog(ll n, ll x) {
    if(x == 0) return 1;
    if(x & 1) return ((n % MOD) * (expoLog(n, x - 1) % MOD)) % MOD;
    ll y = (expoLog(n, x / 2)) % MOD;
    return ((y % MOD) * (y % MOD)) % MOD;
}

void solve(){        
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> divers(n);
    for(int i = 0; i < n; i++) {
        divers[i] = div2(a[i]);
    }
    vector<ll> acum(n + 1, 0);
    vector<ll> remainder(ALL(a));
    for(int i = 0; i < n; i++) {
        while(!(remainder[i] & 1)) {
            remainder[i] /= 2;
        }
    }
    vector<ll> remAcum(n + 1, 0);
    partial_sum(ALL(remainder), remAcum.begin() + 1);
    partial_sum(ALL(divers), acum.begin() + 1);


    vector<pair<ll, ll> > maxis(n);
    maxis[0] = {a[0], 0};
    ll maxi = a[0];
    ll index = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] > maxi) {
            maxi = a[i];
            index = i;
        }
        maxis[i] = {maxi, index};
    }

    for(auto & [i, j] : maxis) cout << i << ' ' << j << endl;

    for(int i = 0; i < n; i++) {
        ll ans = ((maxis[i].first % MOD) * (expoLog(2, acum[i + 1] - div2(a[maxis[i].second])))) % MOD;
        ans = ((ans % MOD) + (remAcum[i + 1] - (remAcum[maxis[i].second + 1] - remAcum[maxis[i].second])));
        cout << ans << ' ';

    }
    cout << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

