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
vector<ll> primes;

void solve(){        
    ll n;
    cin >> n;
    vector<bool> range(2000000, true);
    for(int i = 0; primes[i] * primes[i] <= n + 2000000; i++) {
        ll p = primes[i];
    
        ll s = max(p * p, ((n + p - 1) / p) * p); 

        for(ll j = s; j < n + 2000000; j += p) {
            range[j - n] = false;
        }
    }
    for(ll i = 1; i < 1000000; i++) {
        if(range[i]) {
            cout << i + n << endl;
            return;
        }
    }

    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    vector<bool> sieve(1000010, true);
    sieve[0] = false; sieve[1] = false;
    for(int i = 2; i * i <= 1000010; i++) {
        if(sieve[i]) for(int j = 2 * i; j < 1000010; j += i) {
            sieve[j] = false;
        }
    }
    for(int i = 1; i < 1000010; i++) {
        if(sieve[i]) primes.push_back(i);
    }
    
    while(t--){
        solve();
    }return 0;
}

