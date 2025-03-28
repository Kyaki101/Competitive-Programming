#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
typedef long long int ll;
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;


ll choose2(ll n) {
    return (n * (n - 1)) / 2;
}

void solve(){        
    ll k;
    cin >> k;
    if(k == 0) {
        cout << 0 << endl;
        return;
    }
    ll x = 1;
    ll y = 1;
    vector<pair<ll, ll> > points;

    ll tot = 0;

    while(tot < k) {
        ll bruh = 1;
        while(tot + choose2(bruh) <= k) {
            points.push_back({x, y});
            bruh ++;
            y ++;
        }
        tot += choose2(bruh - 1);
        x ++;
        y++;
    }

    cout << points.size() << endl;

    for(auto i : points) {
        cout << i.first << ' ' << i.second << endl;
    }



}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

