#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
typedef long long int ll;
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

void solve(){        
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll> > a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].second;
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
    }
    for(int i = 1; i < n; i++) {
        a[i].second += i;
    }

    ll index = -1;
    ll maxi = 0;
    for(int i = 0; i < n; i++) {
        if(a[i].second <= m && a[i].first > maxi) {
            maxi = a[i].first;
            index = i + 1;
        }
    }
    cout << index << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

