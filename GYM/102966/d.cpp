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

ll m = 1000001;
vector<bool> sieve(m);
vll primes;




ll expo(ll a, ll b, ll mod) {
    a %= mod;
    int ans = 1;
    while(b) {
        if(b%2) ans = (ans*a)%mod;
        a = (a*a)%mod;
        b /= 2;
    }
    return ans;

}

void solve(){        
    ll n;
    cin >> n;
    vll ans;
    for(auto p : primes) {
        if(p == 2) continue;
        ll bruh = expo(2, p, p);
        if((bruh + n) % p == 0) ans.PB(p);
    }
    if(ans.size() == 0) {
        cout << -1 << endl;
        return;
    }
    for(int i = 0; i < (ll)ans.size(); i++) {
        if(i == (ll)ans.size() - 1) {
            cout << ans[i] << endl;
            return;
        }
        cout << ans[i] << ' ';
    }

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin >> t;
    for(int i = 2; i < m; i++) {
        if(!sieve[i]) {
            primes.PB(i);
            for(int j = i + i; j < m; j += i) sieve[j] = true;
        }
    }

    while(t--){
        solve();
        #ifdef ICPC 
            cout << "--------------------------------------------------" << endl;
        #endif // 
    }
    #ifdef ICPC 
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}

