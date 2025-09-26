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
    ll a, b;
    cin >> a >> b;
    if(a % 2 == 0 && (b & 1)) {
        cout << -1 << endl;
        return;
    }
    if(b % 2 == 0 && (a & 1)) {
        if((b / 2) % 2 == 1) {
            cout << -1 << endl;
            return;
        }
        cout << a * (b / 2) + 2 << endl;
        return;

    }
    if(b % 2 == 0 && a % 2 == 0) {
        cout << a * (b / 2) + 2 << endl;
        return;
    }
    cout << b * a + 1<< endl;
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

