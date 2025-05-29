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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for(auto & i : a) cin >> i;

    for(auto & i : b) cin >> i;

    ll mini = (1LL << 60);
    ll maxi = -1;
    bool found = false;
    ll sum = 0;
    for(int i = 0; i < n && !found; i++) {
        if(b[i] != -1) {
            found = true;
            sum = a[i] + b[i];
        }
        mini = min(a[i], mini);
        maxi = max(a[i], maxi);
    }
    if(found) {
        for(int i = 0; i < n; i++) {
            
            if(b[i] == -1) b[i] = sum - a[i];
        }
        for(int i = 0; i < n; i++) {
            if(b[i] > k || b[i] < 0 || a[i] + b[i] != sum) {
                cout << 0 << endl;
                return;
            }
        }
        cout << 1 << endl;
        return;

    }

    ll diff = maxi - mini;
    if(diff > k) {
        cout << 0 << endl;
        return;
    }
    cout << k - diff + 1<< endl;
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

