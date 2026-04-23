#include <algorithm>
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

bool check(ll mid, vll a, ll mini, ll maxi) {
    ll n = a.size();
    set<ll> indices;
    vll bruh;
    for(int i = 0; i < n; i++) {
        if(abs(a[i] - mini) >= mid || abs(a[i] - maxi) >= mid) {
            indices.insert(i);
            bruh.PB(a[i]);
        }
    }
    sort(ALL(bruh));
    ll j = 0;
    for(int i = 0; i < n; i++) {
        if(indices.find(i) != indices.end()) {
            a[i] = bruh[j];
            j++;
        }
    }
    return is_sorted(ALL(a));

}

void solve(){        
    ll n;
    cin >> n;
    vll a(n);
    ll maxi = 0;
    ll mini = (1LL << 60);
    for(auto &i : a) {
        cin >> i;
        maxi = max(i, maxi);
        mini = min(i, mini);
    }
    if(is_sorted(ALL(a))) {
        cout << -1 << endl;
        return;
    }
    ll l = 0;
    ll r = (1LL << 32);
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(check(mid, a, mini, maxi)) {
            l = mid;
        }
        else r = mid;
    }
    cout << l << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        #ifdef ICPC 
            cout << "--------------------------------------------------" << endl;
        #endif // 
    }
    #ifdef ICPC 
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}

