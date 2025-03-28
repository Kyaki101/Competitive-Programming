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


ll possible(ll bun, ll saus, ll cheese, ll bP, ll sP, ll cP, ll rubles, vector<ll> required, ll mid) {
    required[0] *= mid;
    required[1] *= mid;
    required[2] *= mid;


    required[0] = max(0LL, required[0] - bun);

    required[1] = max(0LL, required[1] - saus);

    required[2] = max(0LL, required[2] - cheese);

    ll price = 0;

    price += required[0] * bP;
    price += required[1] * sP;
    price += required[2] * cP;

    return price <= rubles;



    
}

void solve(){        
    string s;
    cin >> s;
    ll bun, saus, cheese;
    cin >> bun >> saus >> cheese;
    ll bP, sP, cP;
    cin >> bP >> sP >> cP;
    ll rubles;
    cin >> rubles;
    ll l = 0;
    ll r = (1LL << 45);
    vector<ll> required(3, 0);
    for(auto i : s) {
        if(i == 'B') required[0] ++;
        if(i == 'S') required[1] ++;
        if(i == 'C') required[2] ++;
    }


    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(possible(bun, saus, cheese, bP, sP, cP, rubles, required, mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;


}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}

