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


bool srt(pair<ll, ll> a, pair<ll, ll> b) {
    return a.second < b.second;
}

void solve(){        
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for(auto &[x, y] : a) cin >> x >> y;
    sort(ALL(a));
    ll lowY, highY, lowX, highX;
    lowX = a[0].first - 1;
    highX = a[n - 1].first + 1;
    sort(ALL(a), srt);
    lowY = a[0].second - 1;
    highY = a[n - 1].second + 1;
    cout << 2 * (highY - lowY) + 2 * (highX - lowX) << endl;


}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

