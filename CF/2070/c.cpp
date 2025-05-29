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
ll n;


bool possible(ll x, string & s, vector<ll> & a, ll k) {
    ll n = s.size();

    bool painting = false;

    for(int i = 0; i < n; i++) {
        if(!painting && s[i] == 'B' && a[i] > x) {
            painting = true;
            k --;
        }
        else if(painting && s[i] == 'R' && a[i] > x) {
            painting = false;
        }
    }

    return k >= 0;
}

void solve(){        
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll r = (1 << 30);
    ll l = -1;
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(possible(mid, s, a, k)) {
            r = mid;
        }
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

