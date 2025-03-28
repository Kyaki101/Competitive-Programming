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

    map<ll, ll> nums;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        nums[a[i]] ++;
    }
    ll ans = 0;

    while(nums.size() != 0) {
        auto it = nums.begin();
        ll prev = it->first - 1;
        ans ++;
        while(it != nums.end() && it->first == prev + 1) {
            ll x = it->first;
            prev = x;
            nums[x] --;
            if(nums[x] == 0) {
                it = nums.erase(it);
            }

            else it++;
        }

    }
    cout << ans << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

