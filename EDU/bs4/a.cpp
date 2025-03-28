#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define double long double
typedef long long int ll;
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;


ll rAns = 0, lAns = 0;


bool possible(double x, ll d, vector<ll> & a) {
    ll n = a.size();
    vector<double> acum(n + 1);
    vector<double> mins(n + 1, 0);
    vector<ll> pos(n + 1, 0);
    acum[0] = 0;
    for(int i = 1; i <= n; i++) {

        acum[i] = acum[i - 1] + (a[i - 1] - x);

    }
    mins[0] = 0;
    pos[0] = 0;
    for(int i = 1; i <= n; i++) {
        if(acum[i] < mins[i - 1]) {
            mins[i] = acum[i];
            pos[i] = i;
        }
        else {
            mins[i] = mins[i - 1];
            pos[i] = pos[i - 1];
        }
    }


    for(int i = d; i <= n; i++) {
        if(mins[i - d] <= acum[i]) {
            rAns = i;
            lAns = ( 1 + pos[i - d]);
            return true;
        }
    }


    return false;

}

void solve(){        
    ll n, d;
    cin >> n >> d;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }



    double r = 110;
    double l = -0.000003;
    ll passes = 0;
    while(passes < 110) {
        double mid = (r + l) / 2;
        if(possible(mid, d, a)) {
            l = mid;
        }
        else r = mid;
        passes ++;
    }
    cout << lAns << ' ' << rAns << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}
