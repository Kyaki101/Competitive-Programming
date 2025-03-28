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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll suma = 0;
    suma = accumulate(ALL(a), 0LL);
    vector<ll> mad(n);
    map<ll, ll> mapa;
    ll maxi = 0;
    for(int i = 0; i < n; i++) {
        mapa[a[i]] ++;
        if(mapa[a[i]] >= 2 && a[i] > maxi) {
            maxi = a[i];
        }
        mad[i] = maxi;
    }
    ll streak = 0;
    bool found = false;
    ll prev = 0;
    for(int i = 0; i < n; i++) {
        if(mad[i] != prev) {
            streak = 1;
            prev = mad[i];
        }

        suma += mad[i] * streak;
        streak ++;
    }
    cout << suma << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

