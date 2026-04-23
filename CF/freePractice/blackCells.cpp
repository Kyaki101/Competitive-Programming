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
    sort(ALL(a));

    if(n == 1) {
        cout << 1 << endl;
        return;
    }

    ll maxi = 0;

    if(!(n & 1)) {
        for(int i = 0; i < n; i++,i++) {
            maxi = max(maxi, a[i + 1] - a[i]);
        }
        cout << maxi << endl;
        return;
    }



    ll ans = (1LL << 61);
    for(int i = 0; i < n; i++, i++) {
        ll bruh = 0;
        for(int j = 0; j < n - 1; j++, j++) {
            if(i == j) j++;
            bruh = max(a[j + 1] - a[j], bruh);
        }
        ans = min(bruh, ans);
    }
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

