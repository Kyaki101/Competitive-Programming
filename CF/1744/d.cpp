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

void solve(){        
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<pair<ll, ll>> powers(n, {0, 0});
    for(int i = 1; i <= n; i++) {
        powers[i - 1].second = i;
        ll x = i;
        while(x % 2 == 0) {
            x /= 2;
            powers[i - 1].first ++;
        }
    }
    sort(powers.rbegin(), powers.rend());
    for(auto &i : a) cin >> i;
    ll twos = 0;
    for(int i = 0; i < n; i++) {
        while(a[i] % 2 == 0) {
            twos ++;
            a[i] /= 2;
        }
    }
    if(twos >= n) {
        cout << 0 << endl;
        return;
    }
    ll count = 0;
    for(int i = 0; i < n; i++) {
        twos += powers[i].first;
        count ++;
        if(twos >= n) {
            cout << count << endl;
            return;
        }
    }
    cout << -1 << endl;
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

