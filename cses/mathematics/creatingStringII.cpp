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

vector<ll> fact(1000001);

ll expo(ll n, ll x) {
    if(x == 0) return 1;
    if(x & 1) return (n * expo(n, x - 1)) % MOD;
    ll y = expo(n, x / 2);
    return (y * y) % MOD;
}

void solve(){        
    string s;
    cin >> s;
    ll n = s.size();
    map<ll, ll> mapa;
    for(auto i : s) mapa[i] ++;
    ll bottom = 1;
    for(auto i : mapa) {
        bottom = (bottom * fact[i.second]) % MOD;
    }
    ll inv = expo(bottom, MOD - 2);
    cout << (fact[n] * inv) % MOD << endl;


    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    fact[0] = 1;
    for(int i = 1; i <= 1000001; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    while(t--){
        solve();
    }return 0;
}

