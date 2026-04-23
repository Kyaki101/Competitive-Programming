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
    ll n, k, q, m;
    cin >> n >> k >> q;
    vector<vll> mat(n, vll(k));
    for(auto &i : mat) for(auto &j : i) cin >> j;
    for(int j = 0; j < k; j++) {
        for(int i = 1; i < n; i++) {
            mat[i][j] = mat[i][j] | mat[i - 1][j];
        }
    }
    while(q--) {
        cin >> m;
        map<ll, pair<ll, ll>> mapa;
        while(m --) {
            ll region, c;
            char bruh;
            cin >> region >> bruh >> c;
            region --;
            if(mapa.find(region) == mapa.end()) {
                mapa[region] = {-1, (1LL << 60)};
            }
            pair<ll, ll> &curr = mapa[region];
            if(bruh == '>') curr.first = max(curr.first, c + 1);
            else curr.second = min(curr.second, c - 1);
        }
        bool found = true;
        vector<pair<ll, ll>> pot;

        for(auto &[region, limits] : mapa) {
            pair<ll, ll> curr;
            if(limits.first > limits.second) {
                found = false;
                break;
            }
            ll l = -1;
            ll r = n;
            while(l + 1 < r) {
                ll mid = (l + r) / 2;
                if(mat[mid][region] >= limits.first) r = mid;
                else l = mid;
            }
            if(r == n) {
                found = false;
                break;
            }
            curr.first = r + 1;
            l = -1;
            r = n;
            while(l + 1 < r) {
                ll mid = (l + r) / 2;
                if(mat[mid][region] <= limits.second) l = mid;
                else r = mid;
            }
            if(l == -1) {
                found = false;
                break;
            }
            curr.second = l + 1;

            pot.PB(curr);
            
        }

        if(!found) {
            cout << -1 << endl;
            continue;
        }

        ll mini = pot[0].first;
        ll maxi = pot[0].second;
        for(int i = 1; i < (ll)pot.size(); i++) {
            mini = max(mini, pot[i].first);
            maxi = min(maxi, pot[i].second);
        }
        if(mini <= maxi) {
            cout << mini << endl;
        }
        else cout << -1 << endl;
    }



    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
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

