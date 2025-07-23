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

void solve(){        
    ll n;
    cin >> n;
    ll maxi = 0;
    vector<set<ll>> mat(n);
    ll tot = 0;
    set<ll> full;
    for(int i = 0; i < n; i++) {
        ll k;
        cin >> k;
        for(int j = 0; j < k; j++) {
            ll x;
            cin >> x;
            mat[i].insert(x);
            full.insert(x);
        }
    }
    for(auto e : full) {
        set<ll> curr;
        for(auto &s : mat) {
            if(s.find(e) == s.end()) {
                for(auto i : s) curr.insert(i);
            }
        }
        maxi = max((ll)curr.size(), maxi);
    }
    cout << maxi << endl;

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

