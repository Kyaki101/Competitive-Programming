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
    ll n, m, k;
    cin >> n >> m >> k;
    ll l = 0;
    vector<ll> ans(n, 0);
    ll fit = (m + 1) * k;
    ll maxi = n / fit;

    for(int i = 0; i < maxi; i++) {
        ll index = i;
        while(index < n) {
            ans[index] = i;
            index += max(k, maxi);
        }
    }
    for(auto i : ans) {
        cout << i << ' ';
    }
    cout << endl;

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

