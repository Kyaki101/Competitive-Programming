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
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    sort(ALL(a));
    ll mex = 0;
    ll prev = -1;
    ll emer - 1;
    bool used = false;
    for(int i = 0; i < n; i++) {
        if(a[i] != prev + 1 && used) break;
        if(a[i] != prev + 1 && !used) {
            emer = prev + 1;
            prev ++;
            mex ++;
            i--;
            continue;
        }
        mex++;
        prev++;
    }
    ll x;
    if(emer != -1) {
        cout << emer << endl;
    }
    else {
        cout << mex << endl;
        mex ++;
    }
    cin >> x;
    while(x != -1) {
        if(x >= mex) {
            cout << mex << endl;
            mex ++;
        }
        else {
            cout << x << endl;
        }
        cin >> x;
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

