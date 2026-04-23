#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define F second
#define S first
#define PB push_back
#define ll long long
typedef vector<ll> vll;

const int MAX = 2e5+20, MOD = 1e9+7;

void solve(){        
    ll n;
    cin >> n;
    vll a(n), b(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    ll p = 0, q = 0;
    vll suffA(n + 1), suffB(n + 1);
    for(int i = n - 1; i > -1; i--) {
        if(a[i] == 1) suffA[i] = suffA[i + 1] + 1;
        else suffA[i] = suffA[i + 1];
        if(b[i] == 1) suffB[i] = suffB[i + 1] + 1;
        else suffB[i] = suffB[i + 1];
    }
    for(int i = 0; i < n; i++) {
        if(a[i] == -1 && b[i] == -1) {
            if(suffA[i + 1] + p > suffB[i + 1] + q) {
                p--;
            }
            else {
                q--;
            }
            continue;
        }
        if(a[i] == 1 && b[i] == 1) {
            if(p + suffA[i + 1] < q + suffB[i + 1]) {
                p++;
            } 
            else q++;
            continue;
        }
        if(a[i] == 1) p++;
        if(b[i] == 1) q++;
    }
    cout << min(p, q) << endl;
    
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

