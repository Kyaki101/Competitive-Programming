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

ll arr[26] = {0};
ll perm[26] = {0};

void solve(){        
    ll n, m;
    cin >> n >> m;
    string s, o;
    cin >> s >> o;
    for(auto i : o) {
        arr[i - 'a'] ++;
        perm[i - 'a'] ++;
    }
    ll l = 0, ans = 0;
    for(int r = 0; r < n; r++) {
        arr[s[r] - 'a'] --;
        while(l <= r && arr[s[r] - 'a'] < 0) {
            if(arr[s[l] - 'a'] != perm[s[l] - 'a']) {
                arr[s[l] - 'a'] ++;
                l++;
            }
        }
        ans += r - l + 1;
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

