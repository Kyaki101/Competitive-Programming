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


ll msb(ll n) {
    ll i = 0;
    ll ans = 0;
    while(i < 30) {
        if(TEST(n, i)) {
            ans = i;
        }
        i++;
    }
    return ans;
}

void solve(){        
    ll n;
    cin >> n;
    vector<ll> a(n, 0);
    set<ll> nums;
    if((n & (n - 1)) == 0) {
        a[n - 1] = n;
        a[n - 2] = n - 1;
        a[n - 3] = CLEAR(n - 1, msb(n - 1));
        a[n - 4] = (n - 1) - 1;
        a[n - 5] = (n - 1) - 2;
        nums.insert(a[n - 1]);
        nums.insert(a[n - 2]);
        nums.insert(a[n - 3]);
        nums.insert(a[n - 4]);
        nums.insert(a[n - 5]);
        ll b = 1;
        for(int i = 0; i < n - 5; i++) {
            while(nums.find(b) != nums.end()) {
                b++;
            }
            a[i] = b;
            b++;
        }


        cout << (1LL << msb(n)) * 2 - 1 << endl;
        for(auto i : a) cout << i << ' '; cout << endl;
        return;
    }

    if(!(n & 1)) {
        a[n - 1] = (1LL << msb(n)) - 1;
        a[n - 2] = n;
        a[n - 3] = n - 1;
        ll b = 1;
        for(int i = 0; i < n - 3; i++) {
            if(i + 1 == a[n - 1]) {
                b ++;
            }
            a[i] = b;
            b ++;
        }
        cout << (1LL << msb(n)) * 2 - 1 << endl;;
        for(auto i : a) cout << i << ' '; cout << endl;
    }

    if(n&1){
        cout<<n<<endl;
        for(int i=2; i<n-2; ++i) cout<<n-1-i<<' ';
        cout<<1<<' '<<n-2<<' '<<n-1<<' '<<n<<endl;
    }

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

