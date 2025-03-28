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
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> mapa;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mapa[a[i]] = i + 1;
    }
    if(n <= 2) {
        cout << "YES" << endl;
        return;
    }

    if(mapa[1] != 1 && mapa[1] != n || mapa[2] != n && mapa[2] != 1) {
        cout << "NO" << endl;
        return;
    }
    priority_queue<ll> pq;
    ll dist = n - 1;
    ll mid = (n + 1) / 2;
    pq.push(min(mid - 1, n - mid));
    set<ll> taken;
    taken.insert(1);
    taken.insert(n);
    for(int i = 3; i <= n; i++) {
        auto it = taken.lower_bound(mapa[i]);
        ll nxt = *it;
        it--;
        ll bef = *it;
        if(min(mapa[i] - bef, nxt - mapa[i]) < pq.top()) {
            cout << "NO" << endl;
            return;
        }
        mid = (bef + mapa[i]) / 2;
        pq.pop();
        pq.push(min(mid - bef, mapa[i] - mid));
        mid = (mapa[i] + nxt) / 2;
        pq.push(min(mid - mapa[i], nxt - mid));
        taken.insert(mapa[i]);
        


    }
    cout << "YES" << endl;


}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

