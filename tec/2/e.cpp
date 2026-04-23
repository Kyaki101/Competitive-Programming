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
    ll n, m;
    cin >> n >> m;
    vll a(n);
    for(auto &i : a) cin >> i;
    string s;
    cin >> s;

    ll l = 0;
    ll r = n - 1;
    vll ord;
    for(int i = 0; i < n - 1; i++) {
        if(s[i] == 'R') {
            ord.PB(a[r]);
            r--;
        }
        else {
            ord.PB(a[l]);
            l++;
        }
    }
    reverse(ALL(ord));
    vll ans;
    ll curr = (a[l] % m);
    ans.PB(curr);
    for(int i = 0; i < n - 1; i++) {
        curr = ((curr % m) * (ord[i] % m)) % m;
        ans.PB(curr);
    }
    reverse(ALL(ans));
    for(auto i : ans) {
        cout << i << ' ';
    }
    cout << endl;
    
    
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

