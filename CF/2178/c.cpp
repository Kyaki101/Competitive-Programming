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
    for(auto &i : a) cin >> i;
    vll suff(n + 1, 0);
    for(int i = n - 1; i > -1; i--) {
        suff[i] = suff[i + 1] + (-a[i]);
    }
    vll norm(n, 0);
    norm[0] = a[0];
    ll first = 0;
    ll acum = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] >= 0) {
            norm[i] = a[i] + acum + a[first];
            acum += a[first];
            first = i;
        }
        else {
            norm[i] = -a[i] + acum + a[first];
            acum -= a[i];
        }
    }
    ll maxi = -(1LL << 60);
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            maxi = suff[i + 1];
            continue;
        }
        if(i == n - 1) {
            maxi = max(maxi, norm[i - 1]);
            continue;
        }
        maxi = max(maxi, norm[i - 1] + suff[i + 1]);
    }
    cout << maxi << endl;


    
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

