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


bool good(vector<ll> & a, ll x) {
    vector<pair<ll, ll>> ranges;
    ll divs = 1;
    ll prev = a[0] + x;
    for(int i = 1; i < a.size(); i++) {
        ll diff = a[i] - prev;
        if(diff > x) {
            divs ++;
            prev = a[i] + x;
        } 

    }
    return divs <= 3;
}

void solve(){        
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    sort(ALL(a));
    ll l = -1;
    ll r = (1LL << 40);
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(good(a, mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
    
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

