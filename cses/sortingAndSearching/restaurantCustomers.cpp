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
    ll n;
    cin >> n;
    vector<pair<ll, bool>> ans(n * 2);
    for(int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        ans[i * 2] = {a, 1};
        ans[i * 2 + 1] = {b, 0};
    }
    sort(ALL(ans));
    ll res = 0;
    ll curr = 0;
    for(int i = 0; i < ans.size(); i++) {
        if(ans[i].second) {
            curr ++;
        }
        else curr --;
        res = max(res, curr);

    }
    cout << res<< endl;

    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

