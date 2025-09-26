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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    sort(ALL(a));
    sort(ALL(b));
    ll i = 0, j = 0;
    ll ans = 0;
    while(i < n && j < m) {
        if(b[j] >= a[i] - k && b[j] <= a[i] + k) {
            ans ++; i++; j++;
        }
        else if(b[j] > a[i] + k) i++;
        else if(b[j] < a[i] - k) j++;
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

