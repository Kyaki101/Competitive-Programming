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
    ll n, k;
    cin >> n >> k;
    vector<ll> p(n);
    for(auto &i : p) cin >> i;
    vector<ll> d(n);
    for(auto &i : d) cin >> i;
    ll q;
    cin >> q;
    vector<ll> qu(q);
    for(auto &i : qu) cin >> i;
    for(int i = 0; i < q; i++) {
        ll index = 0;
        for(int j = 0; j < n; j++) {
            if(qu[j] <= p[index]) break;
            else index ++;
        }
        if(index == n) {
            cout << "YES" << endl;
            continue;
        }
        ll time = 0;
        if(qu[i] != p[index]) {
            time = (abs(p[index] - qu[i])) % k;
        }
        ll it = 0;
        vector<bool> vis(n, false);
        ll dir = 1;
        bool passed = false;
        while(it < 100000) {
            DEBUG(time);
            if(vis[index]) {
                break;
            }
            if(time % k == d[index]) {
                dir *= -1;
                vis[index] = true;
            }
            if(index + dir == n || index + dir == -1) {
                passed = true;
                break;
            }

            time = (time + abs(p[index] - p[index + dir])) % k;
            it++;
        }
        if(passed) {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
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

