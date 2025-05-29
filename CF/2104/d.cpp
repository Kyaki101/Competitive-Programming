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


vector<bool> sieve(10000000, false);
vector<ll> primes;

void solve(){        
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto & i : a) {
        cin >> i;
    }
    ll points = 0;
    sort(a.rbegin(), a.rend());
    for(int i = 0; i < n; i++) {
        points += a[i] - primes[i];
        if(points < 0) {
            cout << n - i << endl;
            return;
        }
    }
    cout << 0 << endl;


}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    sieve[0] = true;
    sieve[1] = true;
    for(int i = 2; i * i < 10000000; i++) {
        if(sieve[i] == false) {
            for(int j = 2 * i; j < 10000000; j += i) {
                sieve[j] = true;
            }
        }
    }
    for(int i = 2; i < 10000000; i++) {
        if(sieve[i] == false) {
            primes.push_back(i);
        }
    }
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

