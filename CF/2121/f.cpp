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
    ll n, sum, x;
    cin >> n >> sum >> x;
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    map<ll, ll> pref;
    map<ll, ll> reserve;
    reserve[0] ++;
    ll curr = 0;
    bool found = false;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > x) {
            pref.clear();
            reserve.clear();
            reserve[0] ++;
            curr = 0;
            continue;
        }
        if(a[i] == x) {
            for(auto &i : reserve) {
                pref[i.first] += i.second;
            }
            reserve.clear();
        }
        curr += a[i];
        ans += pref[curr - sum];
        reserve[curr] ++;
    }
    cout << ans << endl;
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

