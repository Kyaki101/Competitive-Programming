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
ll n;


void fill(ll n, vector<ll> & lost) {
    for(int i = 0; i < 60; i ++) {
        if(TEST(n, i)) lost[i] ++;
    }
}


void calc(ll n, vector<ll> & lost, vector<ll> & val, ll index) {
    for(int i = 0; i < 60; i++) {
        if(TEST(n, i)) val[index] -= (1LL << i) * lost[i];
    }
}

void plusl(ll size, ll n, vector<ll> & lost, vector<ll> & val, ll index) {
    for(int i = 0; i < 60; i++) {
        if(TEST(n, i)) {
            ll better = size - lost[i];
            val[index] += (1LL << i) * better;
        }
    }
}

void solve(){        
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> lost(60, 0);

    for(int i = 0; i < n; i++) {
        fill(a[i], lost);
    }

    vector<ll> val(n, 0);
    for(int i = 0; i < n; i++) {
        calc(a[i], lost, val, i);
        plusl(n, a[i], lost, val, i);
    }

    ll maxi = -1 * (1LL << 60);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(val[i] > maxi) {
            ans = a[i];
            maxi = val[i];
        }

    }
    ll suma = 0;

    for(int i = 0; i < n; i++) {
        suma += ans ^ a[i];
    }

    cout << suma << endl;


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

