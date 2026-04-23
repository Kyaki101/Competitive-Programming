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
    ll n;
    cin >> n;
    ll adv1;
    cout << 1 << ' ' << 1 << ' ' << n << endl;
    cin >> adv1;
    ll adv2;
    cout << 2 << ' ' << 1 << ' ' << n << endl;
    cin >> adv2;
    ll adv = adv2 - adv1;
    ll l = 1;
    ll r = n + 1;
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        ll ans1, ans2;
        cout << 1 << ' ' << mid << ' ' << n << endl;
        cin >> ans1;
        cout << 2 << ' ' << mid << ' ' << n << endl;
        cin >> ans2;
        if(ans2 - ans1 < adv) {
            r = mid;
        }
        else l = mid;
    }
    cout << '!' << ' ' << l << ' ' << l + adv - 1 << endl;
    
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

