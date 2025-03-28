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
    vector<ll> a(2 * n);
    set<ll> nums;
    for(int i = 0; i < 2 * n; i++) {
        cin >> a[i];
        nums.insert(a[i]);
    }
    sort(a.rbegin(), a.rend());
    ll num = 0;
    for(int i = 0; i < 2 * n; i++) {
        if(i & 1) num -= a[i];
        else num += a[i];
    }
    cout << num << ' ';

    for(auto i : a) cout << i << ' ';
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

