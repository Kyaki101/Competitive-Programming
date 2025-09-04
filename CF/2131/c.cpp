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
    ll n, k;
    cin >> n >> k;
    multiset<ll> a, b;
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        x %= k;
        a.insert(x);
    }
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        x %= k;
        b.insert(x);
    }
    for(auto i : a) {
        if(b.find(i) != b.end()) {

            b.erase(b.find(i));
        }
        else if(b.find(abs(i - k)) != b.end()) {
            b.erase(b.find(abs(i - k)));
        }
        else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

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

