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
    if(n & 1 && n < 26) {
        cout << "-1" << endl;
        return;
    }
    if(n & 1) {
        vector<ll> ans(n);
        ans[0] = 1;
        ans[9] = 1;
        ans[25] = 1;
        ans[10] = 2;
        ans[26] = 2;
        ll num = 3;
        for(int i = 1; i < n; i++, i++) {
            if(i == 9 || i == 25) {
                continue;
            }
            ans[i] = num;
            ans[i + 1] = num;
            num ++;
        }

        for(auto i : ans) cout << i << ' '; cout << endl;
        return;
    }
    ll num = 1;
    vector<ll> ans;
    for(int i = 0; i < n; i++, i++) {
        ans.push_back(num);
        ans.push_back(num);
        num ++;
    }
    for(auto i : ans) cout << i << ' '; cout << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

