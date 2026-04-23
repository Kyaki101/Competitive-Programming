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
    ll n, p;
    cin >> n >> p;
    vll a(n);
    ll suma = 0;
    for(auto &i : a) cin >> i, suma += i;
    for(int i = 0; i < n; i++) {
        a.PB(a[i]);
    }
    if(p % suma == 0) {
        cout << 1 << ' ' << n * (p / suma) << endl;
        return;
    }
    ll iters = p / suma;
    ll k = p % suma;
    ll l = 0;
    ll mini = (1 << 30);
    ll curr = 0;
    ll start = 0;
    for(int r = 0; r < 2 * n; r++) {
        curr += a[r];
        while(curr - a[l] >= k) {
            curr -= a[l];
            l++;
        }
        if(curr >= k) {
            if(r - l + 1 < mini) {
                start = l;
                mini = r - l + 1;
            }
        }
    }
    cout << start + 1 << ' ' << iters * n + mini << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

