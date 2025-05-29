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
ll n;

void solve(){        
    ll n;
    cin >> n;
    ll x = n * 2;
    vector<ll> a(x);
    for(int i = 0; i < x; i++) {
        cin >> a[i];
    }

    vector<ll> ans(x + 1, 0);

    sort(ALL(a));
    ll suma = 0;
    for(int i = 0; i < n + 1; i++) {
        ans[2 * i] = a[n + i - 1];
    }

    for(int i = 0; i < n; i++) {
        ans[2 * i + 1] = a[i];
    }

    ans[2 * n - 1] = 0;

    for(int i = n - 1; i < x; i++) {
        ans[2 * n - 1] += a[i];
    }


    for(int i = 0; i < n - 1; i++) {
        ans[2 * n - 1] -= a[i];
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

