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


bool possible(ll x, vector<ll> & a, ll k) {
    if(x == 0) return true;
    ll n = a.size();
    unordered_set<ll> stash;
    ll count = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] < x) {
            stash.insert(a[i]);
        }
        if(stash.size() == x) {
            stash.clear();
            count ++;
        }
    }
    return count >= k;
 
 
    
}

void solve(){        
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll l = 0;
    ll r = (1 << 20);
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(possible(mid, a, k)) l = mid;
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
    }return 0;
}

