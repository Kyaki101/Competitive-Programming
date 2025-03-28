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
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    ll r = 0;
    ll del = 0;
    for(int i = 1; i <= n - k; i++) {
        cout << i << endl;
        if(r + k <= n - i) {
            del += a[i];
            pq.push(a[i]);
            r += k;
        }
        else {
            vector<ll> stash;
            ll pre = del;
            ll prer = r;
            while(r + k > n - i + 1) {
                stash.push_back(pq.top());
                del -= pq.top();
                r -= k;
                pq.pop();
            }
            del += a[i];
            if(del <= pre) {
                r -= a[i];
                for(auto j : stash) pq.push(j);
                del = pre;
                r = prer;
                r --;
            }
            else r += k, pq.push(a[i]);

        }

    }
    cout << del << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

