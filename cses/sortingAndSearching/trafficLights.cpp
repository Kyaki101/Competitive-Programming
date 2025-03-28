#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
typedef long long int ll;
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

void solve(){        
    ll x, n;
    cin >> x >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<ll> pts;
    multiset<ll, greater<ll> > ranges;
    pts.insert(x);
    pts.insert(0);
    ranges.insert(x);
    for(int i = 0; i < n; i++) {
        if(a[i] == 0 || a[i] == x) continue;
        auto it = pts.lower_bound(a[i]);
        ll nxt = *it;
        it--;
        ll bef = *it;
        ranges.erase(ranges.find(nxt - bef));
        ranges.insert(a[i] - bef);
        ranges.insert(nxt - a[i]);
        pts.insert(a[i]);
        cout << *ranges.begin() << ' ';

    }
    cout << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    t = 1;
    while(t--){
        solve();
    }return 0;
}

