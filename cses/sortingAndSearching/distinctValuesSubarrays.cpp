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
    vll a(n);
    for(auto &i : a) cin >> i;
    set<ll> nums;
    ll old = 0;
    ll ans = 0;
    queue<ll> q;
    for(int i = 0; i < n; i++) {
        if(nums.find(a[i]) != nums.end()) {
            ll c = q.size();
            ans += ((c * (c + 1)) / 2) - ((old * (old + 1)) / 2);
            while(q.front() != a[i]) {
                nums.erase(q.front());
                q.pop();
            }
            q.pop();
            old = q.size();
            q.push(a[i]);
            if(i == n - 1) ans += ((q.size() * (q.size() + 1)) / 2) - ((old * (old + 1)) / 2);
        }
        else if(i == n - 1) {
            q.push(a[i]);
            ll c = q.size();
            ans += ((c * (c + 1)) / 2) - ((old * (old + 1)) / 2);
        }
        else {
            q.push(a[i]);
            nums.insert(a[i]);
        }
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

