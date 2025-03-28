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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);


    priority_queue<ll> pq;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pq.push(a[i]);
    }
    vector<bool> colors(n, false);

    ll ans = 0;

    
    if(k > 1) {
        while(k > -1) {
            ans += pq.top();
            pq.pop();
            k--;

        }
        cout << ans << endl;
        return;
        
    }

    ll maxi = 0;
    for(int i = 0; i < n; i++) {
        if(i == 0) maxi = max(a[0] + a[n - 1], maxi);
        else if(i == n - 1) maxi = max(a[n - 1] + a[0], maxi);
        else maxi = max(max(a[0] + a[i], a[n - 1] + a[i]), maxi);
    }
    cout << maxi << endl;




}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

