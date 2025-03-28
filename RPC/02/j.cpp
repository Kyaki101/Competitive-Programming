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
    int n;
    cin >> n;
    vector<pair<ll, ll> > a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    for(int i = 1; i < n; i++) {
        if(a[i].first < a[i - 1].first || a[i].second < a[i - 1].second) {
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}

