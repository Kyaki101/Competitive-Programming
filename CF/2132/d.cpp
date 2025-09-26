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


vector<ll> dp(19, 0);

ll digitSum(ll n) {
    if(n < 10) {
        return (n * (n + 1)) / 2;
    }
    ll d = (ll)(log10(n));
    ll p = (ll)(ceil(pow(10LL, d)));
    ll msd = n / p;

    return (msd * dp[d] + ((msd * (msd - 1)) / 2) * p + msd * (1 + n % p) + digitSum(n % p));
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
    ll n = (k - 1) / l + (ll)pow(10LL, l - 1);
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
    dp[0] = 0;
    dp[1] = 45;
    for(int i = 2; i <= 18; i++) {
        dp[i] = dp[i - 1] * 10 + 45 * (ll)(ceil(pow(10LL, i - 1)));
    }
    while(T--){
        solve();
        //cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}

