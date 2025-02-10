#include <bits/stdc++.h>
using namespace std;
#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) (cout << (n) << endl)
#define CLEAN(arr) (memset(arr, 0, sizeof(arr)))
#define ALL(v) (v).begin(), (v).end()
#define MOD 1000000007


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

const int MAX = 2e5+20;

ll inv;


ll rangeSum(ll a, ll b) {
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}

ll expoInv(ll n, ll x) {
    if(x == 0) return 1;
    if(x & 1) return ((n % MOD) * (expoInv(n, x - 1) % MOD)) % MOD;
    ll y = expoInv(n, x / 2) % MOD;
    return ((y % MOD) * (y % MOD)) % MOD;
}

void sol(){        
    ll n;
    cin >> n;
    ll sum = 0;
    ll starter;
    starter = 1;
    for(ll i = 1; i * i < n; i++) {
        sum = (sum % MOD + ((i * (n / i)) % MOD)) % MOD;
        if((i + 1) * (i + 1) >= n) starter = i + 1;
    }
    inv = expoInv(2, MOD - 2);
    ll half = n / 2;
    ll preSum = ((n % MOD) * ((n + 1) % MOD)) % MOD;
    ll fullSum = (preSum * (inv % MOD)) % MOD;
    ll stup = ((half % MOD) * ((half + 1) % MOD)) % MOD;
    ll halfSum = (stup * (inv % MOD)) % MOD;
    sum = ((sum % MOD) + (rangeSum(fullSum, halfSum) % MOD)) % MOD;
    while(starter < half + 1) {
        ll l = starter;
        ll r = half + 1;
        while(l + 1 < r) {
            ll m = (r + l) / 2;
            if(n / m == n / starter) {
                l = m;
            }
            else r = m;

        }
        ll pre = starter - 1;
        ll preSum = ((l % MOD) * ((l + 1) % MOD)) % MOD;
        ll stup = ((pre % MOD) * ((pre + 1) % MOD)) % MOD;
        ll bruh = rangeSum((preSum * inv) % MOD, (stup * inv) % MOD) % MOD;
        bruh = ((bruh % MOD) * ((n / starter) % MOD)) % MOD;
        sum = ((sum % MOD) + (bruh % MOD)) % MOD; 
        starter = l + 1;
    }
    cout << sum << endl;


}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

              
    int t;
    t = 1;
    while(t--){
        sol();
    }


    return 0;
}

