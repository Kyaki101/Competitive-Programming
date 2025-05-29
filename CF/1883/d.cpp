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

void solve(){        
    ll n;
    cin >> n;
    multiset<ll> ls;
    multiset<ll> rs;
    while(n--) {
        char c;
        cin >> c;
        ll l, r;
        cin >> l >> r;
        if(c == '+') {
            ls.insert(l);
            rs.insert(r);
        }
        else {
            ls.erase(ls.find(l));
            rs.erase(rs.find(r));
        }
        if(rs.size() == 0) {
            cout << "NO" << endl;
            continue;
        }
        ll lowest = *rs.begin();
        if(ls.upper_bound(lowest) == ls.end()) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
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

