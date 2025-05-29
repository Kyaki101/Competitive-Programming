#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define pb push_back
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
ll n;

void solve(){        
    ll n, m;
    cin >> n >> m;
    vector<set<ll>> nums(n);
    for(int i = 0; i < n; i++) {
        ll l;
        cin >> l;
        for(int j = 0; j < l; j++) {
            ll k;
            cin >> k;
            nums[i].insert(k);
        }
    }


    vector<set<ll, greater<ll>>> ans(n);

    for(int i = 0; i < n; i++) {
        ll prev = -1;
        auto it = nums[i].begin();
        bool stop = false;
        while(it != nums[i].end()) {
            ll v = *it;
            if(v != prev + 1 && !stop) {
                ans[i].insert(prev + 1);
                prev = prev + 1;
                stop = true;
                continue;
            }
            if(v != prev + 1 && stop) {
                it = nums[i].end();
                continue;
            }
            ans[i].insert(v);
            prev = v;
            if(++it == nums[i].end() && !stop) {
                ans[i].insert(v + 1);
            }

        }
    }

    vector<ll> mex(n);
    for(int i = 0; i < n; i++) {
        if(ans[i].size() == 0) {
            mex[i] = 0;
            continue;
        }
        ll v = *ans[i].begin();
        mex[i] = v + 1;

    }

    ll limit = 0;
    for(auto i : mex) {
        limit = max(mex[i], limit);
    }
    limit = min(limit, m);

    ll sum = limit * (limit + 1);
    if(limit != m) {
        ll sub = (limit * (limit + 1)) / 2;
        ll upper = (m * (m + 1)) / 2;
        sum += upper - sub;
    }
    cout << sum << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

