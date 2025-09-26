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
    if(n == 1 && m == 1) {
        cout << 1 << endl;
        return;
    }
    ll lower = n;
    ll upper = (n * (n + 1)) / 2;
    if(m < lower || m > upper) {
        cout << -1 << endl;
        return;
    }
    vector<ll> ans;
    set<ll, greater<ll>> nums;
    for(int i = 2; i <= n; i++) {
        nums.insert(i);
    }
    ll currSum = 0;
    auto it = nums.begin();
    while(it != nums.end()) {

        ll lowest = n - ans.size() - 1;
        if(currSum + *it + lowest <= m) {
            ans.PB(*it);
            currSum += *it;
            it = nums.erase(it);
        }
        else it++;
    }
    vector<pair<ll, ll>> edges;

    ll dumb = ans.size();
    dumb --;
    for(int i = 0; i < dumb; i++) {

        edges.PB({ans[i], ans[i + 1]});
    }

    if(ans.size() != 0) edges.PB({ans[ans.size() - 1], 1});
    for(auto i : nums) {
        edges.PB({1, i});
    }
    cout << edges[0].first << endl;
    for(auto &[x, y] : edges) {
        cout << x << ' ' << y << endl;
    }

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

