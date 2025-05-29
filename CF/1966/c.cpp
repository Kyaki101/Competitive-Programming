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


ll ladder(set<ll> & a) {
    auto it = a.begin();
    auto nxt = a.begin();
    nxt ++;
    ll size = 1;
    while(nxt != a.end()) {
        if(*nxt != *it + 1) {
            return size;
        }
        nxt ++;
        it ++;
        size ++;
    }
    return size;

}

void solve(){        
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto &i : a) {
        cin >> i;
    }
    set<ll> nums(ALL(a));
    if(*nums.begin() == 1) {
        ll lad = ladder(nums);
        if(lad == nums.size() && (nums.size() & 1)) {
            cout << "Alice" << endl;
            return;
        }
        if(lad % 2 ==  0 && lad != nums.size()) {
            cout << "Alice" << endl;
            return;
        }
        cout << "Bob" << endl;
        return;
    }

    cout << "Alice" << endl;
    return;
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

