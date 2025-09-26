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
    multiset<ll> ms;
    for(int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        ms.insert(a);
    }
    for(int i = 0; i < m; i++) {
        ll x;
        cin >> x;
        if(ms.size() == 0) {
            cout << -1 << endl;
            continue;
        }
        auto it = ms.lower_bound(x);
        if(*it > x || it == ms.end()) {
            if(it == ms.begin()) {
                cout << "-1" << endl;
                continue;
            }
            it--;
        }
        cout << *it << endl;
        ms.erase(it);
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

