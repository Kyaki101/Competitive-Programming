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
    ll k = m;
    if(m == 0) {
        cout << n << endl;
        return;
    }
    m = n + m;

    ll index = 0;
    for(int i = 0; i < 60; i ++) {
        if(TEST(m, i) && !(TEST(n, i))) {
            index = i;
        }
    }

    if(n > 0) {
        ll l = max(0LL, n - k);
        ll bruh = 0;
        for(int i = 0; i < 60; i++) {
            if(TEST(n, i) && !TEST(l, i)) {
                bruh = i;
            }
        }
        for(int i = 0; i <= bruh; i++) {
            l = SET(l , i);
        }
        n = l | n;
    }

    for(int i = 0; i <= index; i++) {
        n = SET(n, i);
    }
    cout << n << endl;
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

