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

ll ans(ll n) {
    vector<bool> sieve(100000, false);
    ll end = sqrt(n + 100000);

    for(int i = 2; i <= end; i++) {
        for(int j = i - (n % i); j <= 100000; j += i) {
            if(i == j + n) continue;
            sieve[j] = true;
        }
    }
    for(int i = 1; i <= 100000; i++) {
        if(!sieve[i]) {
            return i + n;
        }
    }
    return 0;
}

void solve(){        
    ll n;
    cin >> n;
    cout << ans(n) << endl;
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

