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
ll n;

void solve(){        
    ll n;
    cin >> n;
    vector<vector<ll>> mat(n, vector<ll>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    ll b = n * 2;
    ll ex = (b * (b + 1)) / 2;
    ll suma = 0;
    set<ll> nums;
    vector<ll> ans(b + 1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(nums.find(mat[i][j]) == nums.end()) {
                suma += mat[i][j];
            }
            nums.insert(mat[i][j]);
            ans[i + 1 + j + 1] = mat[i][j];
            
        }

    }
    ans[1] = ex - suma;
    for(int i = 1; i <= b; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
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

