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
    ll a = x, b = (1LL << (n + 1)) - x;
    vector<ll> ans;
    while(a != b) {
        if(a < b) {
            b -= a;
            a *= 2;
            ans.PB(1);
        }
        else if(b < a) {
            a -=b;
            b *= 2;
            ans.PB(2);
        }
    }
    reverse(ALL(ans));
    cout << ans.size() << endl;
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

