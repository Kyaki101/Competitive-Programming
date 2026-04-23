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
    stack<ll> bruh;
    ll mini = a[0];
    bruh.push(a[0]);
    vector<pair<ll, ll>> edges;

    for(int i = 1; i < n; i++) {

        ll minix = a[i];
        while(bruh.size() && bruh.top() < a[i]) {
            minix = min(minix, bruh.top());
            edges.PB({a[i], bruh.top()});
            bruh.pop();
        }
        bruh.push(minix);

        mini = min(a[i], mini);
    }

    if((ll)edges.size() == n - 1) {
        cout << "YES" << endl;
        for(auto [x, y] : edges) {
            cout << x << ' ' << y << endl;
        }
        return;
    }

    cout << "NO" << endl;
    
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

