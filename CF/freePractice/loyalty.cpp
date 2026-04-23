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
    ll n, x;
    cin >> n >> x;
    vll a(n);
    for(auto &i : a) cin >> i;
    ll i = 0;
    ll j = n - 1;
    ll val = 0;

    auto check = [&](ll num) {
        return num >= x - (val % x);

    };
    vll ans;
    ll s = 0;
    sort(ALL(a));
    while(i <= j) {
        if(i == j) {
            if(check(a[j])) {
                s += a[j];
            }
            ans.PB(a[j]);
            j--;
            continue;
        }
        if(check(a[j])) {
            ans.PB(a[j]);
            val += a[j];
            s += a[j];
            j--;
            continue;
        }
        ans.PB(a[i]);
        val += a[i];
        i++;
    }
    cout << s << endl;
    for(auto k : ans) {
        cout << k << ' ';
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

