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

ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

void solve(){        
    ll a, b, c, m;
    cin >> a >> b >> c >> m;
    ll g = lcm(a, lcm(b, c));
    ll allInter = (m / g);
    ll abInter = (m / lcm(a, b)) - allInter;
    ll acInter = (m / lcm(a, c)) - allInter;
    ll bcInter = (m / lcm(b, c)) - allInter;
    ll acount = allInter * 2 + abInter * 3 + acInter * 3 + ((m / a) - abInter - acInter - allInter) * 6;
    ll bcount = allInter * 2 + abInter * 3 + bcInter * 3 + ((m / b) - abInter - bcInter - allInter) * 6;
    ll ccount = allInter * 2 + bcInter * 3 + acInter * 3 + ((m / c) - acInter - bcInter - allInter) * 6;

    cout << acount << ' ' << bcount << ' ' << ccount << endl;



    
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

