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
    ll operations = 0;
    for(int i = 1; i < n; i+= 2) {
        if(i == n - 1) {
            ll diff = a[i - 1] - a[i];
            if(diff > 0) {
                ll points = a[i - 1] - max(0LL, a[i - 1] - diff);
                a[i - 1] = max(0LL, a[i - 1] - diff);
                operations += points;
            }
            continue;
        }
        ll enemy = a[i - 1] + a[i + 1];
        ll diff = enemy - a[i];
        if(diff > 0) {
            ll points = a[i + 1] - max(0LL, a[i + 1] - diff);
            a[i + 1] = max(0LL, a[i + 1] - diff);
            operations += points;
        }
        diff = (a[i - 1] + a[i + 1]) - a[i];
        if(diff > 0) {
            ll points = a[i - 1] - max(0LL, a[i - 1] - diff);
            a[i - 1] = max(0LL, a[i - 1] - diff);
            operations += points;
        }
    }
    cout << operations << endl;
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

