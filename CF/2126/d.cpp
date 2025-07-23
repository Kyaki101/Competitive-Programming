#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define pb push_back
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;


bool srt(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b) {
    if(a.first.first != b.first.first) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

void solve(){        
    ll n, k;
    cin >> n >> k;
    vector<pair<pair<ll, ll>, ll>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first.first >> a[i].first.second >> a[i].second;
    }
    sort(ALL(a), srt);
    set<ll> nums;
    nums.insert(k);
    for(int i = 0; i < n; i++) {
        auto it = nums.lower_bound(a[i].first.first);
        if(it != nums.end() && *it <= a[i].first.second) {
            nums.insert(a[i].second);
        }
    }

    for(int i = n - 1; i > -1; i--) {
        auto it = nums.lower_bound(a[i].first.first);
        if(it != nums.end() && *it <= a[i].first.second) {
            nums.insert(a[i].second);
        }
    }
    auto it = nums.end();
    it --;
    cout << (*it) << endl;

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

