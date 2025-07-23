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
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    ll chosen = a[k - 1];
    sort(ALL(a));
    if(n == 1) {
        cout << "YES" << endl;
        return;
    }
    ll start = 0;
    while(a[start] != chosen) {
        start++;
    }
    ll time = 0;
    for(int i = start; i < n - 1; i++) {
        ll diff = a[i + 1] - a[i];
        if(diff + time > a[i]) {
            cout << "NO" << endl;
            return;
        }
        time += diff;

    }
    cout << "YES" << endl;
    return;

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

