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

void solve(){        
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    if(b < a) {
        if(b == a - 1 && (a & 1)) {
            cout << y << endl;
            return;
        }
        cout << -1 << endl;
        return;
    }
    if(x <= y) {
        cout << x * (b - a) << endl;
        return;
    }
    if(a & 1) {
        cout << x * (((b - a) + 1) / 2) + y * ((b - a) / 2) << endl;
        return;
    }
    cout << y * (((b - a) + 1) / 2) + x * ((b - a) / 2) << endl;
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

