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

ll finder(ll i, ll j, vll &cFacts, ll n) {
    ll l = -1;
    ll r = cFacts.size();
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(cFacts[mid] * i * j <= n) l = mid;
        else r = mid;
    }

    if (l > -1 && cFacts[l] * i * j == n) {
        return cFacts[l];
    }
    return 0;
}

void solve(){        
    ll a, b, c;
    cin >> a >> b >> c;
    ll n;
    cin >> n;
    vll aFacts, bFacts, cFacts;
    for(ll i = 1; i * i <= a; i++) {
        if(a % i == 0) {
            aFacts.PB(i);
            if(i * i != a) aFacts.PB(a / i);
        }
    }
    for(ll i = 1; i * i <= b; i++) {
        if(b % i == 0) {
            bFacts.PB(i);
            if(i * i != b) bFacts.PB(b / i);
        }
    }
    for(ll i = 1; i * i <= c; i++) {
        if(c % i == 0) {
            cFacts.PB(i);
            if(i * i != c) cFacts.PB(c / i);
        }
    }

    sort(ALL(aFacts));
    sort(ALL(bFacts));
    sort(ALL(cFacts));

    for(int i = 0; i < (int)aFacts.size(); i++) {
        for(int j = 0; j < (int)bFacts.size(); j++) {
            ll bruh = finder(aFacts[i], bFacts[j], cFacts, n);
            if(bruh) {
                cout << aFacts[i] - 1 << ' ' << bFacts[j] - 1 << ' ' << bruh - 1<< endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
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

