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


ll euclid(ll a, ll b, ll &x, ll &y) {
    if(!b) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = euclid(b, a % b, x1, y1);

    x = y1;
    y = x1 - y1 * (a / b);
    return g;

}

void solve(){        
    ll a, b;
    while(cin >> a) {
        cin >> b;
        ll x, y;
        ll g = euclid(a, b, x, y);
        cout << x << ' ' << y << ' ' << g << endl;

    }

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    while(T--){
        solve();
        //cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}

