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

priority_queue<pair<ll, ll>> pq;

bool bfs(pair<ll, ll> num, vector<ll> & a, vector<bool> & vis, vll & ordered, ll & i, set<pair<ll, ll>> & nums) {
    bool bruh = false;
    if(nums.find(num) == nums.end()) {
        pq.push(num);
        nums.insert(num);
        bruh = true;
    }
    while(!pq.empty() && i < a.size() && pq.top().first == ordered[i]) {
        auto [x, y] = pq.top();
        pq.pop();
        if(vis[y]) {
            continue;
        }
        vis[y] = true;
        ll j = y + 1;
        if(j < a.size() && !vis[j] && nums.find({a[j], j}) == nums.end()) {
            pq.push({a[j], j});
            nums.insert({a[j], j});
        }
        j = y - 1;
        if(j > -1 && !vis[j] && nums.find({a[j], j}) == nums.end()) {
            pq.push({a[j], j});
            nums.insert({a[j], j});
        }

        i++;

    }
    return bruh;


}

void solve(){        
    ll n;
    cin >> n;
    vector<ll> a(n);
    priority_queue<pair<ll, ll>> pp;
    pq = pp;
    for(auto &i : a) cin >> i;
    map<ll, ll> cnt;
    map<pair<ll, ll>, ll, greater<pair<ll, ll>>> pos;
    for(int i = 0; i < n; i++) {
        cnt[a[i]] ++;
        pos[{a[i], cnt[a[i]]}] = i;
    }
    ll curr = 0;
    vector<bool> vis(n, false);
    vll ordered = a;
    sort(ordered.rbegin(), ordered.rend());
    set<pair<ll, ll>> nums;
    ll ans = 0;
    for(auto &[p, index] : pos) {
        if(!vis[index]) {
            ans += bfs({p.first, index}, a, vis, ordered, curr, nums);
        }
    }
    cout << ans << endl;


}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    ll bruh = 1;
    while(t--){
        solve();
    }return 0;
}

