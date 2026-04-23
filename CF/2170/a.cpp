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

ll movs[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void solve(){        
    ll counter = 1;
    ll n;
    cin >> n;
    vector<vll> mat(n, vll(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            mat[i][j] = counter;
            counter ++;
        }
    }
    auto valid = [&](ll i, ll j) {
        return i >= 0 && j >= 0 && i < n && j < n;
    };
    ll maxi = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ll ans = mat[i][j];
            for(int k = 0; k < 4; k++) {
                ll x = i + movs[k][0];
                ll y = j + movs[k][1];
                if(valid(x, y)) {
                    ans += mat[x][y];
                }
            }
            maxi = max(maxi, ans);
        }
    }
    cout << maxi<< endl;
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

