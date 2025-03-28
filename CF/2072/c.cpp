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


bool cust(ll x, ll y) {
    return (x & y) == y;
}

void solve(){        
    ll n, x;
    cin >> n >> x;
    vector<ll> ans;
    ll num = 0;
    ll temp = 0;
    ll index = 0;
    while(index < n - 1 && cust(x, temp)) {
        ans.push_back(temp);
        num |= temp;
        temp ++;
        index ++;
    }
    if(index == n - 1 && (num | temp) == x) {
        ans.push_back(temp);
        index ++;
    }
    for(int i = index; i < n; i++) {
        ans.push_back(x);
    }
    for(auto i : ans) {
        cout << i << ' ';
    }
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

