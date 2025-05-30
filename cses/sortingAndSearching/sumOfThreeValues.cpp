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
    vector<pair<ll, ll>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(ALL(a));
    for(int l = 0; l < n; l++) {
        ll i = 0; 
        ll j = n - 1;
        while(i < j) {
            if(i == l) {
                i++;
                continue;
            }
            if(j == l) {
                j--;
                continue;
            }
            if(a[l].first + a[i].first + a[j].first == k) {
                cout << a[l].second + 1 << ' ' << a[i].second + 1 << ' ' << a[j].second + 1 << endl;
                return;
            }
            if(a[l].first + a[i].first + a[j].first > k) {
                j--;
                continue;
            }
            if(a[l].first + a[i].first + a[j].first < k) {
                i++;
                continue;
            }
        }

    }
    cout << "IMPOSSIBLE" << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

