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
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    if(k <= 2) {
        cout << "YES" << endl;
        return;
    }
    vector<ll> b(ALL(a));
    sort(ALL(b));
    ll x = b[k - 2];
    vector<ll> c;
    for(int i = 0; i < n; i++) {
        if(a[i] <= x) c.push_back(a[i]);
    }
    ll l = 0;
    ll r = c.size() - 1 ;
    vector<int> used(c.size(), 0);
    while(l <= r) {
        if(c[l] == c[r]) {
            used[l] = 1;
            used[r] = 1;
            r --;
            l ++;
            continue;
        }
        if(c[l] == x || c[r] == x) {
            if(c[l] == x) {
                l ++;
            }
            else r --; 
            continue;
        }
        cout << "NO" << endl;
        return;
    }
    ll ans = 0;
    for(auto i : used) {
        ans += i;
    }
    if(ans < k - 1) {
        cout << "NO" << endl;
        return;
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

