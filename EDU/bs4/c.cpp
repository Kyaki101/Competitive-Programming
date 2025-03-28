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


bool possible(vector<pair<ll, ll> > & pairs, double x, ll k) {
    vector<double> lista;
    for(int i = 0; i < pairs.size(); i++) {
        lista.push_back(pairs[i].first - (x * pairs[i].second));
    }

    sort(lista.rbegin(), lista.rend());

    double suma = 0;
    for(int i = 0; i < k; i++) {
        suma += lista[i];
    }
    return suma >= 0;
}

void solve(){        
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll> > a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }


    double r = (1 << 30);
    double l = 0;
    ll count = 0;
    while(count < 100) {
        double mid = (l + r) / 2;
        if(possible(a, mid, k)) l = mid;
        else r = mid;
        count ++;
    }

    cout << setprecision(12) << l << endl;




    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}

