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
    ll bruh = accumulate(ALL(a), 0LL);
    ll mini = (1LL << 60);
    ll maxi = 0;
    for(int i = 0; i < n; i++) {
        mini = min(a[i], mini);
        maxi = max(a[i], maxi);
    }
    if(maxi - mini > k + 1) {
        cout << "Jerry" << endl;
        return;
    }
    ll c = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] - mini > k) {
            c++;
        }
    }
    if(c > 1) {
        cout << "Jerry" << endl;
        return;
    }
    if(bruh & 1) {
        cout << "Tom" << endl;
        return;
    }
    cout << "Jerry" << endl;
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

