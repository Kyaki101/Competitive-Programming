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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(ALL(a));
    ll ini = 0;
    ll fin = m - 1;
    vector<pair<ll, ll>> ans(n);
    for(int i = 0; i < n; i++) {
        if(i & 1) {
            ans[i].first = ans[i - 1].second;
            ans[i].second = ans[i - 1].first;

        }
        else {
            ans[i].first = a[ini];
            ans[i].second = a[fin];
            ini ++;
            fin --;

        }

    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cout << ans[i].first << ' ' << ans[i].second << ' ';
        }
        cout << endl;
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

