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


ll digitSum(ll n) {
    ll res = 0;
    ll factor = 1;
    
    while(n > 0) {
        ll d = n % 10;
        n /= 10;
        res += d * (d - 1) / 2 * factor;
        res += d * (n * 45 * factor);
        factor *= 10;
    }
    return res;
}


void solve(){        
    ll k;
    cin >> k;
    ll l = 1;
    ll curr = 9;
    while(k - l * curr > 0) {
        k -= l * curr;
        l++;
        curr *= 10;
    }
    ll n = (k - 1) / l + (ll)pow(10, l - 1);
    string num = to_string(n);
    ll ans = 0;
    for(int i = 0; i < (k - 1) % l + 1; i++) {
        ans += num[i] - '0';
    }

    ans += digitSum(n - 1);
    cout << ans << endl;

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

