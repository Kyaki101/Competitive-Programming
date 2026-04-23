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
    ll n, h;
    cin >> n >> h;
    vll a(n);
    for(auto &i : a) cin >> i;
    
    vector<vll> maxis(n, vll(n));
    for(int i = 0; i < n; i++) {
        maxis[i][i] = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] > a[maxis[i][j - 1]]) maxis[i][j] = j;
            else maxis[i][j] = maxis[i][j - 1];
        }
    }


    vll cnt(n);
    for(int i = 0; i < n; i++) {
        ll maxi = a[i];
        for(int j = i; j < n; j++) {
            maxi = max(a[j], maxi);
            cnt[i] += h - maxi;
        }
        maxi = a[i];
        for(int j = i - 1; j > -1; j--) {
            maxi = max(a[j], maxi);
            cnt[i] += h - maxi;
        }
    }


    ll ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            ans = max(ans, cnt[i] + cnt[j] - cnt[maxis[i][j]]);
        }
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

