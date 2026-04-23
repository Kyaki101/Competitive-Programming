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
    ll ans = 0;
    vector<ll> pos(n);
    vector<ll> neg(n);
    for(int i = 0; i < n; i++) {
        if(i == 0 && a[i] < 0) {
            pos[i] = 0;
            continue;
        }
        if(a[i] < 0) {
            pos[i] = pos[i - 1];
            continue;
        }
        if(i == 0) {
            pos[i] = a[i];
        }
        else {
            pos[i] = pos[i - 1] + a[i];
        }
    }

    for(int i = n - 1; i > -1; i--) {
        if(i == n - 1 && a[i] > 0) {
            neg[i] = 0;
            continue;
        }
        if(a[i] > 0) {
            neg[i] = neg[i + 1];
            continue;
        }
        if(i == n - 1) {
            neg[i] = abs(a[i]);
            continue;
        }

        neg[i] = neg[i + 1] + abs(a[i]);
    }
    for(int i = 0; i < n; i++) {
        ans = max(neg[i] + pos[i], ans);
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

