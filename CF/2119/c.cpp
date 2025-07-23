#include <bits/stdc++.h>
using namespace std;

#define SET(m,i) ((m)|(1ULL<<(i)))
#define TEST(m,i) ((m)&(1ULL<<(i)))
#define CLEAR(m,i) ((m)&~(1ULL<<(i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define DEBUG_ALL(a) for(auto &w:a)cout<<w<<' ';cout<<endl;
#define ALLN(x,n) begin(x), begin(x)+n
#define ALL(x) begin(x), end(x)
#define vec vector
#define snd second
#define fst first
#define pb push_back
#define ll long long
const ll MAX = 2e5+20, MOD = 1e9+7;

ll msb(ll n) {
    ll ans = 0;
    for(int i = 0; i < 62; i++) {
        if(TEST(n, i)) {
            ans = i;
        }
    }
    return ans;
}

void solve(){        
    ll n, l, r, k;
    cin >> n >> l >> r >> k;
    if(n == 2) {
        cout << -1 << endl;
        return;
    }
    if(n & 1) {
        cout << l << endl;
        return;
    }
    ll nxt = msb(l) + 1;
    ll pos = (1LL << nxt);
    if(pos <= r) {
        if(k >= n - 1) {
            cout << pos << endl;
            return;
        }
        cout << l << endl;
        return;
    }
    cout << -1 << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
        //cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}

