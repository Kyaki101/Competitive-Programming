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

void solve(){        
    auto query = [&](ll i, ll j, ll k) {
        ll x;
        cout << "? " << i << ' ' << j << ' ' << k << endl;
        cin >> x;
        return x;

    };
    auto ans = [&](ll i, ll j, ll k) {
        cout << "! " << i << ' ' << j << ' ' << k << endl;
        return;
    };
    ll n;
    cin >> n;

    vector<vll> triangles;
    set<vll> vis;
    triangles.PB({1, 2, 3});
    vis.insert({1, 2, 3});

    ll i = 0;
    while((ll)triangles.size() > i) {
        vll temp = triangles[i];
        ll x = query(temp[0], temp[1], temp[2]);
        if(x == 0) {
            ans(temp[0], temp[1], temp[2]);
            return;
        }

        if(vis.find({temp[0], temp[1], x}) == vis.end()) {
                triangles.PB({temp[0], temp[1], x});
                vis.insert({temp[0], temp[1], x});
        }

        if(vis.find({temp[0], temp[2], x}) == vis.end()) {
            triangles.PB({temp[0], temp[2], x});
            vis.insert({temp[0], temp[2], x});
        }

        if(vis.find({temp[1], temp[2], x}) == vis.end()) {
            triangles.PB({temp[1], temp[2], x});
            vis.insert({temp[1], temp[2], x});
        }


        i++;
    }
    cout << 1 << ' ' << 1 << ' ' << 1 << endl;

    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        #ifdef ICPC 
            cout << "--------------------------------------------------" << endl;
        #endif // 
    }
    #ifdef ICPC 
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}

