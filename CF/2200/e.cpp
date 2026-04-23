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
 
const int MAX = 1000001, MOD = 1e9+7;
 
 
vector<vll> sieve(1000001);
 
void solve(){        
    ll n;
    cin >> n;
    vll a(n);
    for(auto &i : a) cin >> i;
 
    if(is_sorted(ALL(a))) {
        cout << "Bob" << endl;
        return;
    }
 
    vll ans;
    for(int i = 0; i < n; i++) {
        if(sieve[a[i]].size() > 1) {
            cout << "Alice" << endl;
            return;
        }
        vll temp = sieve[a[i]];
 
        ll num = a[i];
        if(num == 1) {
            ans.PB(1);
            continue;
        }
        for(auto d : temp) {
            while(num % d == 0) {
                ans.PB(d);
                num /= d;
            }
        }
        
 
    }
 
    if(is_sorted(ALL(ans))) {
        cout << "Bob" << endl;
        return;
    }
    cout << "Alice" << endl;
    
}
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    for(int i = 2; i < MAX; i++) {
        if(sieve[i].empty()) {
            sieve[i].PB(i);
            for(int j = i * 2; j < MAX; j += i) {
                sieve[j].PB(i);
            }
        }
    }
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
 
