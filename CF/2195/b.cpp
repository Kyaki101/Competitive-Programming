#include <algorithm>
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
    vll a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<bool> taken(n + 1, false);
    vector<vll> bruh;
    for(int i = 1; i <= n; i++) {
        ll x = i;
        if(!taken[x]) {
            vll temp;
            vll comp;
            while(x <= n) {
                temp.PB(a[x]);
                comp.PB(x);
                taken[x] = true;
                x *= 2;
            }
            sort(ALL(temp));
            if(comp != temp) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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

