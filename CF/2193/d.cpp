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
    vll a(n), b(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    sort(a.rbegin(), a.rend());
    vll bruh(n);
    partial_sum(ALL(b), bruh.begin());
    ll maxVal = 0;

    for(int i = 0; i < n; i++) {
        ll temp = a[i];
        ll l = -1;
        ll r = n;
        while(l + 1 < r) {
            ll mid = (l + r) / 2;
            if(bruh[mid] <= i + 1) l = mid;
            else r = mid;
        }
        maxVal = max(maxVal, a[i] * (l + 1));
    }
    cout << maxVal << endl;
    
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

