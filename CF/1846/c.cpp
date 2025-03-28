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


bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    if(a.first != b.first) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

void solve(){        
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll> > mat(n, vector<ll>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        sort(ALL(mat[i]));
    }
    vector<pair<ll, ll> > reses(n);
    for(int i = 0; i < n; i++) {
        ll sum = 0;
        ll suma = 0;
        ll res = 0;
        for(int j = 0; j < m && sum + mat[i][j] <= k; j++) {

            suma += mat[i][j] + sum;
            sum += mat[i][j];
            res ++;
        }
        reses[i] = {res, suma};
    }
    pair<ll, ll> keep = reses[0];
    /**/
    /*for(auto i : reses) {*/
    /*    cout << i.first << ' ' << i.second << endl;*/
    /*}*/

    sort(reses.rbegin(), reses.rend(), cmp);


    for(int i = 0; i < n; i++) {
        if(reses[i] == keep) {
            cout << i + 1 << endl;
            return;
        }
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

