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
    vector<ll> a(3, 0);
    ll steps = 0;
    bool f = false;
    while(a[0] < n && a[2] < n) {
        if(!f) {
            a[2] = min(n, a[0] * 2 + 1);
            a[1] =min(n,  a[0] * 2 + 1);
            steps ++, steps++;
            f = true;
        }
        else {
            a[0] =min(n,  a[2] * 2 + 1);
            a[1] =min(n,  a[1] * 2 + 1);
            steps ++, steps ++;
            f = false;
        }
    }
    cout << steps + 1<< endl;
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

