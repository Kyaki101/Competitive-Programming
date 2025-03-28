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
    vector<ll> a(n - 1);
    for(int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }
    vector<ll> ans;
    ans.push_back(a[0]);
    ll prev = a[0];
    bool got = false;

    for(int i = 1; i < n - 1; i++) {
        if(!got && a[i] > prev) {
            ans.push_back(0);
            ans.push_back(a[i]);
            got = true;
        }
        else if(i >= 2 && prev > a[i] && a[i - 2] == prev && got) {
            ans[ans.size() - 1] = a[i];
            ans.push_back(a[i]);
        }
        else {
            ans.push_back(a[i]);
        }
        prev = a[i];

    }

    if(ans.size() < n) {
        ans.push_back(0);
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

