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
    vll a(n);
    for(auto &i : a) {
        cin >> i;
    }
    for(int i = 1; i < n - 1; i++) {
        if(a[i] == -1) a[i] = 0;
    }
    if(a[0] == -1 && a[n - 1] == -1) {
        a[0] = a[n - 1] = 0;
    }
    else if(a[0] == -1) {
        a[0] = a[n - 1];
    }
    else if(a[n - 1] == -1) {
        a[n - 1] = a[0];
    }
    ll ans = a[n - 1] - a[0];
    cout << abs(ans) << endl;
    for(auto i : a) cout << i << ' ';
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

