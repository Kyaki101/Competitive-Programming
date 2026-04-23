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

bool cmp(const pair<ll, ll> & a, const pair<ll, ll> &b) {
    double razonA = (1.0 * a.first) / a.second;
    double razonB = (1.0 * b.first) / b.second;
    return razonA < razonB;
}

struct comp {
    bool operator()(const pair<ll, ll> &a, const pair<ll, ll> &b) const {
        double razonA = (1.0 * a.first) / a.second;
        double razonB = (1.0 * b.first) / b.second;
        return razonA < razonB;
    }
};

void solve(){        
    double m = 3;
    vll a = {1, 6, 5};
    vll b = {8, 1, 2};
    ll n = a.size();
    vector<pair<ll, ll>> c;
    for(int i = 0; i < n; i++) {
        c.PB({a[i], b[i]});
    }
    sort(c.begin(), c.end(), cmp);
    set<pair<ll, ll>, comp> nums(c.begin(), c.end());


    double ans = 0;

    for(int i = 0; i < n; i++) {
        double l = 0.0;
        double r = 2.0;

        for(int j = 0; j < 60; j++) {
            double mid = (l + r) / 2.0;
            if(c[i].first * mid <= m) {
                l = mid;
            }
            else r = mid;
        }
        ans += l * c[i].second;
        m -= l * c[i].first;
    }
    cout << fixed << setprecision(4) << ans << endl;
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

