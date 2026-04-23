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

void comb(ll i, vector<ll> & a, vector<pair<ll, ll>> & ans, pair<ll, ll> curr, ll maxi) {
    if(i == a.size()) {
        ans.PB(curr);
        return;
    }
    pair<ll, ll> cpy = curr;
    if(a[i] <= maxi / cpy.first) {
        cpy.first *= a[i];
        cpy.second ++;
        comb(i + 1, a, ans, cpy, maxi);
    }

    comb(i + 1, a, ans, curr, maxi);

}

void solve(){        
    ll m, n;
    cin >> m >> n;
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    vector<pair<ll, ll>> ans;
    comb(0, a, ans, {1, 0}, m);
    ll res = 0;
    for(auto i : ans) {
        if(i.second == 0) continue;
        if(i.second & 1) {
            res += m / i.first;
        }
        else {
            res -= m / i.first;
        }
    }
    cout << res << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

