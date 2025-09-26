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
    vector<ll> a(n + 1);
    unordered_map<ll, ll> mapa;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        mapa[a[i]] = i;
    }
    ll score = 1;
    for(int i = 1; i < n; i++) {
        if(mapa[i] > mapa[i + 1]) score ++;
    }
    for(int i = 0; i < m; i++) {
        ll e, b;
        cin >> e >> b;
        ll x = a[e], y = a[b];
        bool backE = false, frontE = false;
        bool backB = false, frontB = false;
        if(x > 1) {
            if(mapa[x - 1] > mapa[x]) backE = true;
        }
        if(x < n) {
            if(mapa[x] > mapa[x + 1]) frontE = true;
        }
        if(y > 1) {
            if(mapa[y - 1] > mapa[y]) backB = true;
        }
        if(y < n) {
            if(mapa[y] > mapa[y + 1]) frontB = true;
        }
        swap(a[e], a[b]);
        mapa[x] = b;
        mapa[y] = e;
        if(x > 1) {
            if(!backE && mapa[x - 1] > mapa[x]) {
                score ++;
            }
            if(backE && mapa[x - 1] < mapa[x]) {
                score --;
            }
        }
        if(y > 1) {
            if(!backB && mapa[y - 1] > mapa[y]) {
                score ++;
            }
            if(backB && mapa[y - 1] < mapa[y]) {
                score --;
            }
        }
        if(x < n && x != y - 1) {
            if(!frontE && mapa[x] > mapa[x + 1]) {
                score ++;
            }
            if(frontE && mapa[x] < mapa[x + 1]) {
                score --;
            }
        }
        if(y < n && y != x - 1) {
            if(!frontB && mapa[y] > mapa[y + 1]) {
                score ++;
            }
            if(frontB && mapa[y] < mapa[y + 1]) {
                score --;
            }
        }
        cout << score << endl;

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

