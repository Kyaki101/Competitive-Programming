#include <bits/stdc++.h>
#include <utility>
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
    vll b(n);
    vll c(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    for(auto &i : c) cin >> i;


    ll top = 0, bot = 0;
    vll bruh;

    auto check = [](vll & bruh, vll & a, ll start) {
        ll n = bruh.size();
        ll end = start;
        if(a[0] >= bruh[start]) return false;
        start ++;
        start %= n;
        ll j = 1;
        while(start != end) {
            if(a[j] >= bruh[start]) {
                return false;
            }
            start ++;
            start %= n;
            j++;
        }
        return true;

    };

    for(int i = 0; i < n; i++) {
        if(check(b, a, i)) {
            top ++;

        }

    }

    for(int i = 0; i < n; i++) {
        if(check(c, b, i)) {
            bot ++;
        }

    }
    cout << bot * top * n << endl;

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

