#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
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
    vll a(n), b(n), c(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    for(auto &i : c) cin >> i;
    vll apref(n + 1), bpref(n + 1), cpref(n + 1);
    partial_sum(ALL(a), apref.begin() + 1);
    partial_sum(ALL(b), bpref.begin() + 1);
    partial_sum(ALL(c), cpref.begin() + 1);
    ll tot = accumulate(ALL(a), 0LL);
    ll goal = (tot + 2) / 3;

    vector<ll> bruh = {0, 1, 2};
    vector<vll> acums = {apref, bpref, cpref};
    bool found = false;
    do {
        ll curr = 0;
        vector<pair<ll, ll>> ans(3);
        ll j = 0;
        for(int i = 1; i <= n && curr < 3; i++) {
            if(acums[bruh[curr]][i] - acums[bruh[curr]][j] >= goal) {
                ans[bruh[curr]] = {j + 1, i};
                curr ++;
                j = i;
            }
        }
        if(curr == 3) {
            for(auto [x, y] : ans) {
                cout << x << ' ' << y << ' ';
            }
            cout << endl;
            return;
        }

    } 
    while(next_permutation(ALL(bruh)));

    cout << -1 << endl;


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

