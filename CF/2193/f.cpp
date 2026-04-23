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
    ll n, ax, ay, bx, by;
    cin >> n >> ax >> ay >> bx >> by;
    ll dist = bx - ax;
    map<ll, ll> dpMin;
    map<ll, ll> dpMax;
    vll bruh(n);
    for(int i = 0; i < n; i++) {
        cin >> bruh[i];
        dpMin[bruh[i]] = (1LL << 60);
        dpMax[bruh[i]] = -1 * (1LL << 60);
    }
    for(int i = 0; i < n; i++) {
        ll y;
        cin >> y;
        ll mini = dpMin[bruh[i]];
        ll maxi = dpMax[bruh[i]];
        dpMin[bruh[i]] = min(y, mini);
        dpMax[bruh[i]] = max(y, maxi);
    }
    set<ll> nums(ALL(bruh));
    bruh.clear();
    for(auto i : nums) bruh.PB(i);
    n = bruh.size();

    vll upper(n), lower(n);

    for(int i = 0; i < n; i++) {
        ll xCor = bruh[i];
        if(i == 0) {
            upper[i] = abs(ay - dpMin[xCor]) + abs(dpMax[xCor] - dpMin[xCor]);
            lower[i] = abs(ay - dpMax[xCor]) + abs(dpMin[xCor] - dpMax[xCor]);
            continue;
        }
        ll prevX = bruh[i - 1];
        
        upper[i] = min(lower[i - 1] + abs(dpMin[prevX] - dpMin[xCor]), upper[i - 1] + abs(dpMax[prevX] - dpMin[xCor])) + abs(dpMin[xCor] - dpMax[xCor]);
        lower[i] = min(lower[i - 1] + abs(dpMin[prevX] - dpMax[xCor]), upper[i - 1] + abs(dpMax[prevX] - dpMax[xCor])) + abs(dpMin[xCor] - dpMax[xCor]);
    }


    ll last = bruh[n - 1];

    ll ans = min(upper[n - 1] + abs(dpMax[last] - by), lower[n - 1] + abs(dpMin[last] - by));

    cout << ans + dist << endl;


    
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

