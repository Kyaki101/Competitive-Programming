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
    ll n, q;
    cin >> n >> q;
    vll a(n);
    for(auto &i : a) cin >> i;
    vll ones(n, 0);

    vll onesAcum(n + 1, 0);
    vll acum(n + 1);
    for(int i = 0; i < n; i++) {
        if(a[i] == 1) ones[i] = 1;
    }
    partial_sum(ALL(ones), ++onesAcum.begin());
    partial_sum(ALL(a), ++acum.begin());

    while(q--) {
        ll l, r;
        cin >> l >> r;
        if(l == r) {
            cout << "NO" << endl;
            continue;
        }

        ll len = r - l + 1;
        ll o = onesAcum[r] - onesAcum[l - 1];
        ll suma = acum[r] - acum[l - 1];
        if(o * 2 < suma && suma - (o * 2) >= len - o) {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
    
    
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

