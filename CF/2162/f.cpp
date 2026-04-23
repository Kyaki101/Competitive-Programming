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
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n + 2, 0);
    vector<ll> ans(n + 1);
    ll s1, s2;
    ll qBack = q;
    while(q--) {
        ll x, y;
        cin >> x >> y;
        a[x] ++;
        a[y + 1] --;
        s1 = min(x, s1);
    }
    ll maxi = 0;
    ll curr = 0;
    ll index;
    for(int i = 1; i <= n; i++) {
        curr += a[i];
        if(curr > maxi) {
            index = i;
            maxi = curr;

        }
    }
    if(maxi == qBack) {
        ans[index] = 0;
        ll l = index - 1;
        ll r = index + 1;
        ll bruh = n - 1;
        while(bruh > 0) {
            if(l > 0) {
                ans[l] = bruh;
                bruh --;
                l --;
            }
            if(r <= n && bruh > 0) {
                ans[r] = bruh;
                bruh--;
                r++;
            }
        }
        for(int i = 1; i <= n; i++) {
            cout << ans[i] << ' ';
        }
        cout << endl;
        return;

    }

    ans[s1] = 0;
    ll bruh = n - 1;
    ll start = 1;
    for(int i = 1; i < s1; i++) {
        ans[i] = start;
        start ++;
    }
    ll pos = s1 + 1;
    while(bruh >= start) {
        ans[pos] = bruh;
        bruh--;
        pos++;
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    
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

