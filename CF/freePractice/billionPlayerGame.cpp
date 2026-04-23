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
    ll n, l, r;
    cin >> n >> l >> r;
    vll a(n);
    for(auto &i : a) cin >> i;
    sort(ALL(a));
    ll left = 0;
    ll right = n - 1;
    ll x = 0, y = 0;
    ll ans = 0;

    while(left < n && a[left] <= l) {
        x++;
        left++;
    }
    while(right > -1 && a[right] >= r) {
        y++;
        right --;
    }

    while(left <= right) {
        if(x > y) {
            y++;
            right --;
            continue;
        }
        if(y > x) {
            x++;
            left ++;
            continue;
        }
        if(left == right) break;

        x++; y++;
    
        left ++;
        right --;
    }


    bool chosen = x >= y;
    if(chosen) {
        for(int i = 0; i < left; i++) ans += l - a[i];
        for(int i = n - 1; i > right; i--) ans += a[i] - l;
        cout << ans << endl;
        return;
    }
    for(int i = 0; i < left; i++) ans += r - a[i];
    for(int i = n - 1; i > right; i--) ans += a[i] - r;
    cout << ans << endl;
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        #ifdef ICPC 
            cout << "--------------------------------------------------" << endl;
        #endif // 
    }
    #ifdef ICPC 
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}

