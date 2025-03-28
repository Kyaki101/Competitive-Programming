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


bool possible(double time, vector<double> & p, vector<double> & v) {
    ll n = p.size();
    double l = -(1LL << 30);
    double r = (1LL << 30);
    for(int i = 0; i < n; i++) {
        double lBound = (p[i] - time * v[i]);
        double rBound = (p[i] + time * v[i]);
        l = max(lBound, l);
        r = min(rBound, r);
    }

    return r >= l;
}

void solve(){        
    ll n;
    cin >> n;
    vector<double> p(n);
    vector<double> v(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i] >> v[i];
    }

    double r = 20000000000000;
    double l = 0;
    ll i = 0;
    while(i < 100) {
        double mid = (r + l) / 2;

        if(possible(mid, p, v)) r = mid;
        else l = mid;
        i++;
    }

    cout << std::fixed << std::setprecision(10) << r << endl;




}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}

