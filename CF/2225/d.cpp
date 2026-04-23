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



void solve(){        
    ll n, x;
    cin >> n >> x;
    ll lzeros = 1, lones = 0;
    lzeros += x / 4;
    lones = x / 4;
    if(x % 4 > 1) lones ++;

    ll ans = 0;


    ll rzeros = 1, rones = 0;
    rzeros += n / 4;
    if(n % 4 == 3) rzeros ++;
    rones += n / 4;
    if(n % 4 >= 1) rones ++;
    rzeros -= lzeros;
    rones -= lones;
    ans += ((lzeros % MOD) * (rzeros % MOD)) % MOD;
    ans %= MOD;
    ans += ((lones % MOD) * (rones % MOD)) % MOD;
    ans %= MOD;
    cout << ans << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
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

