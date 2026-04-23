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
    ll n, m;
    cin >> n >> m;
    vll a(n + m + 1), b(n + m + 1);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    vll p, t, badP, badT;
    for(int i = 0; i < n + m + 1; i++) {
        if(a[i] > b[i]) p.PB(a[i]), badP.PB(b[i]);
        else t.PB(b[i]), badT.PB(a[i]);
    }

    vll pGood(p.size() + 1), pBad(p.size() + 1), tGood(t.size() + 1), tBad(t.size() + 1);
    if(!p.empty()) {
        partial_sum(ALL(p), pGood.begin() + 1);
        partial_sum(ALL(badP), pBad.begin() + 1);
    }
    if(!t.empty()) {
        partial_sum(ALL(t), tGood.begin() + 1);
        partial_sum(ALL(badT), tBad.begin() + 1);
    }

    ll pr = 0, tr = 0; 
    ll backP = 0, backT = 0;
    for(int i = 0; i <= n + m; i++) {
        ll x = n, y = m;
        ll left = 0, right = 0;
        if(a[i] > b[i]) {
            pr++;
        }
        else tr ++;
        if(x >= backP) {
            left += pGood[backP], x -= backP;
        }
        else {
            left += pGood[x];
            left += pBad[backP] - pBad[max(x, 0LL)];
            x = 0;
        }
        if(y >= backT) {
            if(backT >= 0) left += tGood[backT], y -= backT;
        }
        else {
            left += tGood[y];
            left += tBad[backT] - tBad[max(y, 0LL)];
            y = 0;
        }



        if(x >= (ll)p.size() - pr) {

            right += pGood[p.size()] - pGood[pr];
        }
        else {
            right += pGood[pr + x] - pGood[pr] + pBad[p.size()] - pBad[pr + x];
        }

        if(y >= (ll)t.size() - tr) {
            right += tGood[t.size()] - tGood[tr];
        }
        else {
            right += tGood[tr + y] - tGood[tr] + tBad[t.size()] - tBad[tr + y];
        }
        cout << left + right << ' ';

        if(a[i] > b[i]) backP ++;
        else backT ++;
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
        #ifdef ICPC 
            cout << "--------------------------------------------------" << endl;
        #endif // 
    }
    #ifdef ICPC 
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}

