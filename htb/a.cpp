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
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    map<string, vll> db;
    for(int i = 0; i < n * 20; i += 20) {
        string id = s.substr(i, 12);
        bitset<12> reg(id);
        ll converted = reg.to_ulong();
        db[s.substr(i + 12, 8)].PB(converted);
    }
    vll dp(n, 0);
    for(int i = n * 20; i < s.size(); i += 8) {
        string bruh = s.substr(i, 8);
        if(db.find(bruh) != db.end()) {
            vll copier = dp;
            for(auto j : db[bruh]) {
                if(j == 0) {
                    dp[0] ++;
                }
                else dp[j] += copier[j - 1];
            }

        }
    }
    cout << dp[n - 1] << endl;

    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

