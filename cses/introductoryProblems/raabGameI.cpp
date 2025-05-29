#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define pb push_back
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;

void solve(){        
    ll n, a, b;
    cin >> n >> a >> b;
    if(a == 0 && b != 0 || b == 0 && a != 0) {
        cout << "NO" << endl;
        return;
    }
    ll x = 1;
    ll lx = 1;
    ll y = 1;
    ll ly = 1;
    ll ties = max(0LL, n - (a + b));
    vector<ll> up, down;
    while(ties > 0) {
        up.push_back(x);
        down.push_back(y);
        x ++, y++;
        ties --;
    }
    if(a > 0) {
        lx = x;
        x += b;
        while(a > 0) {
            up.push_back(x);
            down.push_back(y);
            x++, y++;
            a--;
        }
        x = lx;
    }
    while(b > 0) {
        up.push_back(x);
        down.push_back(y);
        x++;
        y++;
        b--;
    }

    // for(auto i : up) cout << i << ' '; cout << endl;
    // for(auto i : down) cout << i << ' '; cout << endl;
    //
    //
    
    for(int i = 0; i < up.size(); i++) {
        set<ll> nums;
        if(up[i] > n || nums.find(up[i]) != nums.end()) {
            cout << "NO" << endl;
            return;
        }
        nums.insert(up[i]);
    }

    for(int i = 0; i < up.size(); i++) {
        set<ll> nums;
        if(down[i] > n || nums.find(down[i]) != nums.end()) {
            cout << "NO" << endl;
            return;
        }
        nums.insert(down[i]);
    }
    cout << "YES" << endl;
    for(auto i : up) cout << i << ' '; cout << endl;
    for(auto i : down) cout << i << ' '; cout << endl;



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

