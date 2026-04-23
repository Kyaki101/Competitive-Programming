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


ll zCount(string & a) {
    ll count = 0;
    for(auto i : a) {
        if(i == '0') count ++;
        else count = 0;
    }
    return count;
}

bool cmp(string & a, string & b) {
    return zCount(a) > zCount(b);
}



void solve(){        
    ll n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(auto &i : a) cin >> i;
    auto check = [](string & s) {
        bool c = false;
        for(auto i : s) {
            if(i == '0') c = true;
            else c = false;
        }
        return c;
    };

    ll ans = 0;
    vector<string> pool;
    for(int i = 0; i < n; i++) {
        if(!check(a[i])) {
            ans += a[i].size();
        }
        else {
            pool.PB(a[i]);

        }
    }

    sort(ALL(pool), cmp);



    for(int i = 0; i < pool.size(); i++) {
        if(i & 1) {
            ans += pool[i].size();
        }
        else {
            ans += pool[i].size() - zCount(pool[i]);
        }
    }
    if(ans > m) {
        cout << "Sasha" << endl;
        return;
    }
    cout << "Anna" << endl;

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

