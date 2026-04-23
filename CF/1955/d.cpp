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
    ll n, m, k;
    cin >> n >> m >> k;
    vll a(n);
    vll b(m);
    unordered_map<ll, ll> origi;
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i, origi[i]++;
    unordered_map<ll, ll> mapa;
    ll elems = 0;
    for(int i = 0; i < m - 1; i++) {
        mapa[a[i]] ++;
        if(mapa[a[i]] <= origi[a[i]]) elems++;
    }
    ll i = m - 1;
    ll j = 0;
    ll ans = 0;
    while(i < n) {
        mapa[a[i]] ++;
        if(mapa[a[i]] <= origi[a[i]]) elems ++;
        if(elems >= k) ans++;
        mapa[a[j]] --;
        if(mapa[a[j]] < origi[a[j]]) elems--;
        i++;
        j++;
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

