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
    vector<ll> a(n);
    ll maxi = 0;
    vector<ll> mapa(1000001, 0);
    for(auto &i : a) {
        cin >> i;
        maxi = max(maxi, i);
        mapa[i] ++;
    }
    vector<pair<ll, vll>> sieve(maxi + 1);
    for(int i = 2; i <= maxi; i++) {
        sieve[i].first += mapa[i];
        for(int j = i * 2; j <= maxi; j += i) {
            sieve[i].first += mapa[j];
        }
    }
    ll ans = (n * (n - 1)) / 2;
    for(int i = 2; i <= maxi; i++) {
        sieve[i].first = (sieve[i].first * (sieve[i].first - 1)) / 2;
    }


    for(int i = maxi; i >= 2; i--) {
        for(int j = i * 2; j <= maxi; j += i) {
            sieve[i].first -= sieve[j].first;
        }

    }

    ll rev = 0;

    for(int i = 2; i <= maxi; i++) {
        rev += sieve[i].first;
    }

    cout << ans - rev << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

