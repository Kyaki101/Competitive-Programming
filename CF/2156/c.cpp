#include <bits/stdc++.h>
#include <numeric>
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
    vll a(n);
    vll freq(n + 1);
    for(auto &i : a) {
        cin >> i;
        freq[i] ++;
    }
    vll pref(n + 1, 0);
    partial_sum(ALL(freq), pref.begin());

    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ll temp = 0;
        if(4 * i <= n) {
            temp += pref[n] - pref[4 * i - 1];
        }
        for(int j = 1; j <= 3; j++) {
            if(i * j <= n) temp += freq[i * j];
        }
        if(n - temp <= k) {
            ans = i;
        }
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

