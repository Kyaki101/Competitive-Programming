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


bool srt(pair<ll, ll> a, pair<ll, ll> b) {
    if(a.second != b.second) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

void solve(){        
    ll n, m;
    cin >> n >> m;
    vll a(n);
    vector<pair<ll, ll>> b(m);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i.first;
    for(auto &i : b) cin >> i.second;
    sort(ALL(b));
    ll monster = 0;
    multiset<ll> nums(ALL(a));
    vll other;
    for(int i = 0; i < m; i++) {
        auto it = nums.lower_bound(b[i].first);
        if(it != nums.end() && b[i].second > 0) {
            ll num = *it;
            monster ++;
            if(b[i].second > num) {
                nums.erase(it);
                nums.insert(b[i].second);
            }
        }
        else {
            other.PB(b[i].first);
        }
    }
    sort(ALL(other));
    auto it = nums.begin();
    for(int i = 0; i < other.size() && it != nums.end(); i++) {
        while(it != nums.end() && *it < other[i]) {
            it++;
        }
        if(it != nums.end()) {
            monster ++;
            it++;
        }
    }
    cout << monster << endl;
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

