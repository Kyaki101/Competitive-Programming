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
    vll a(n);
    for(auto &i : a) cin >> i;
    vll dp1(k + 1, 0);
    vll dp2(k + 1, 0);
    dp1[0] = 1;
    dp2[0] = 1;
    stack<ll> s1, s2;
    vector<vll> tracker(k + 1, vll(k + 1, 0));
    ll mini = (1 << 30), ans = 0;
    ll l = 0;

    auto transfer = [&]() {
        ll x = s2.top();
        s2.pop();
        s1.push(x);
        for(int i = k - x; i > -1; i--) {
            if(dp1[i]) dp1[i + x] ++, tracker[x][i + x] ++; 
        }
    };

    auto add = [&](ll num) {
        s2.push(num);
        for(int i = k - num; i > -1; i--) {
            if(dp2[i]) dp2[i + num] ++;
        }
    };

    auto check = [&]() {
        for(int i = 0; i <= k; i++) {
            if(dp1[i] && dp2[k - i]) return true;
        }
        return false;

    };

    auto remove = [&]() {
        if(s1.empty()) {
            for(int i = 1; i <= k; i++) {
                dp2[i] = 0;
            }
            while(!s2.empty()) {
                transfer();
            }
        }
        ll x = s1.top();
        s1.pop();
        for(int i = 1; i <= k; i++) {
            if(tracker[x][i]) tracker[x][i] --, dp1[i] --;
        }

    };

    for(int r = 0; r < n; r++) {
        add(a[r]);
        bool rem = false;
        while(check()) {
            rem = true;
            remove();
            l++;
        }
        if(rem) {
            mini = min(mini, r - l + 2);
        }
    }

    if(mini == (1 << 30)) {
        cout << -1 << endl;
        return;
    }
    cout << mini << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

