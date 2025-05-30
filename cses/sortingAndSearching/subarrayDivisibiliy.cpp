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
    map<ll, ll> sums;
    sums[0] = 1;
    for(int i = 0; i < n; i++) {
        if(a[i] < 0) {
            a[i] = ((0) - (abs(a[i]) % n) + n) % n;
        }
        else a[i] = a[i] % n;
    }
    ll curr = 0;
    ll count = 0;
    for(int i = 0; i < n; i++) {
        curr = ((curr % n) + a[i]) % n;
        if(sums.find(curr) != sums.end()) {
            count += sums[curr];
        }
        sums[curr] ++;
    }
    cout << count << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

