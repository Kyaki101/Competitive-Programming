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

const ll tam = 300001;

vector<vll> sieve(tam);

void solve(){        
    ll n;
    cin >> n;
    set<ll> a;
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a.insert(x);
    }
    vector<ll> ans(n + 1, (1 << 30));
    if(a.find(1) != a.end()) {
        ans[1] = 1;
    }
    else ans[1] = -1;
    for(int i = 2; i <= n; i++) {
        for(auto div : sieve[i]) {
            if(a.find(div) != a.end()) {
                if(div == i) ans[i] = 1;
                else if(ans[i / div] != -1) ans[i] = min(ans[i], 1 + ans[i / div]);
            }

        }
        if(ans[i] == (1 << 30)) ans[i] = -1;

    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;

    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    sieve[1].PB(1);
    for(int i = 2; i < tam; i++) {
        sieve[i].PB(i);
        for(int j = i * 2; j < tam; j += i) {
            sieve[j].PB(i);
        }
    }
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

