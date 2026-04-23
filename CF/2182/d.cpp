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

const int MAX = 2e5+20, MOD = 998244353;

ll mul(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

ll expo(ll n, ll x) {
    if(x == 0) return 1;
    if(x & 1) return mul(n, expo(n, x - 1));
    ll y = expo(n, x / 2);
    return mul(y, y);
}

vll facts(51);

void solve(){        
    ll n;
    cin >> n;
    ll k;
    cin >> k;
    vll a(n);
    ll maxi = 0;
    for(auto &i : a) {
        cin >> i;
        maxi = max(maxi, i);
    }
    ll norms = 0;
    ll gods = 0;
    for(auto i : a) {
        if(i == maxi) gods ++;
        else norms ++;
    }
    ll survive = maxi - 1;
    for(int i = 0; i < n; i++) {
        if(a[i] < survive) k -= survive - a[i];
    }
    if(k < 0) {
        cout << 0 << endl;
        return;
    }
    if(k >= norms) {
        cout << facts[n] << endl;
        return;
    }
    ll bot = expo(mul(facts[k], facts[norms - k]), MOD - 2);
    ll bruh = mul(facts[norms], bot);
    cout << mul(mul(facts[gods + k], bruh), facts[norms - k]) << endl;

    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    facts[0] = 1;
    for(int i = 1; i < 51; i++) {
        facts[i] = mul(i, facts[i - 1]);
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

