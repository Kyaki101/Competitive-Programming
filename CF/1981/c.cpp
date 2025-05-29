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
    for(auto & i : a) cin >> i;
    sort(ALL(a));
    ll p = n - 1;
    ll counter = 0;
    ll combo = 0;
    for(int i = 0; i < n; i++) {
        if(i == p) {
            ll diff = ((a[i] - combo) + 1) / 2;
            combo += diff;
            counter += diff;
            a[i] -= diff;
            if(combo > 0 && a[i] > 0) {
                a[i] = max(a[i] - combo, 0LL);
                counter ++;
            }
            counter += a[i];
            break;
        }
        if(combo + a[i] >= a[p]) {
            a[i] -= a[p] - combo;
            counter += a[p] - combo;
            counter ++;
            p --;
            i --;
            combo = 0;
            continue;
        }
        combo += a[i];
        counter += a[i];
    }
    cout << counter << endl;
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

