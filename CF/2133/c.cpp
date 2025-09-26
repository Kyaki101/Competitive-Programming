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
    vector<vll> a(n + 1);
    ll maxi = 0;
    ll chosen;
    for(int x = 1; x <= n; x++) {
        cout << '?' << ' ' << x << ' ' << n << ' ';
        for(int i = 1; i <= n; i++) {
            cout << i << ' ';
        }
        cout << endl;
        ll res;
        cin >> res;
        if(res > maxi) {
            chosen = x;
            maxi = res;
        }
        a[res].PB(x);
    }
    ll curr = chosen;
    ll currVal = maxi - 1;
    vll ans;
    ans.PB(chosen);
    while(currVal > 0) {
        for(auto i : a[currVal]) {
            cout << '?' << ' ' << curr  << ' ' << 2 << ' ' << curr << ' ' << i << endl;
            ll res;
            cin >> res;
            if(res == 2) {
                ans.PB(i);
                curr = i;
                break;
            }
        }
        currVal --;

    }
    cout << "! " << maxi << ' ';
    for(auto i : ans) cout << i << ' ';
    cout << endl;

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

