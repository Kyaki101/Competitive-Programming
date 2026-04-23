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
    ll n, x, y;
    cin >> n >> x >> y;
    x = abs(x);
    y = abs(y);
    string s;
    cin >> s;

    sort(ALL(s));
    ll a = 0, b = 0;
    for(auto i : s) {
        if(i == '8') b++;
        a++;
    }
    
    if(x <= a && y <= b || x <= b && y <= a) {
        cout << "YES" << endl;
        return;
    }
    ll end = a;
    for(; b <= end; b++) {
        if(x <= a && y <= b || x <= b && y <= a) {
            cout << "YES" << endl;
            return;
        }
        a--;
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
    }return 0;
}

