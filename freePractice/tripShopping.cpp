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

void solve(){        
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> b(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;

    ll ini = 0;
    vector<pair<ll, ll>> points;
    for(int i = 0; i < n; i++) {
        if(a[i] > b[i]) swap(a[i], b[i]);
        ini += abs(a[i] - b[i]);
        points.PB({a[i], b[i]});
    }
    sort(ALL(points));
    ll minDist = (1 << 30);
    for(int i = 0; i < n - 1; i++) {
        if(points[i].second > points[i + 1].first) {
            cout << ini << endl;
            return;
        }
        minDist = min(minDist, points[i + 1].first - points[i].second);
    }
    cout << ini + 2 * minDist << endl;
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

