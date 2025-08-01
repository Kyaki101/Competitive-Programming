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
    ll n, c;
    cin >> n >> c;
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    ll multiplier = 1;
    sort(ALL(a));
    ll ans = 0;
    vector<ll> valid;
    for(int i = 0; i < n; i++) {
        if(a[i] <= c) valid.push_back(a[i]);
    }
    ans += a.size() - valid.size();
    sort(valid.rbegin(), valid.rend());
    for(int i = 0; i < valid.size(); i++) {
        valid[i] *= multiplier;
        if(valid[i] > c) {
            ans ++;
        }
        else {
            multiplier *= 2;
        }
    }
    cout << ans << endl;
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

