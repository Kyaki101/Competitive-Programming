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


bool cmp(pair<ll, ll> & a, pair<ll, ll> & b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

void solve(){        
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> a(n);
    for(auto &i : a) {
        cin >> i.first >> i.second;
    }
    sort(ALL(a), cmp);
    priority_queue<ll, vector<ll>, greater<ll>> cola;
    ll f = k;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll it = 0;
        if(!cola.empty()) it = cola.top();
        while(!cola.empty() && it < a[i].first) {
            f ++;
            cola.pop();
            if(!cola.empty()) it = cola.top();
        }
        if(f > 0) {
            ans ++;
            cola.push(a[i].second);
            f--;
        }
    }
    cout << endl;
    for(auto i : a) {
        cout << i.first << ' ' << i.second << endl;
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

