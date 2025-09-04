#include <bits/stdc++.h>
using namespace std;

#define SET(m,i) ((m)|(1ULL<<(i)))
#define TEST(m,i) ((m)&(1ULL<<(i)))
#define CLEAR(m,i) ((m)&~(1ULL<<(i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define DEBUG_ALL(a) for(auto &w:a)cout<<w<<' ';cout<<endl;
#define ALLN(x,n) begin(x), begin(x)+n
#define ALL(x) begin(x), end(x)
#define vec vector
#define snd second
#define fst first
#define pb push_back
#define ll long long
const ll MAX = 2e5+20, MOD = 1e9+7;

vector<ll> powers;

void solve(){        
    ll n, k;
    cin >> n >> k;

    ll price = 0;
    ll pointer = powers.size() - 1;
    ll deals = 0;
    vector<ll> slots(powers.size(), 0);
    while(pointer > -1) {
        if(powers[pointer] > n) {
            pointer --;
            continue;
        }
        slots[pointer] ++;
        price += powers[pointer + 1] + pointer * powers[max(0LL, pointer - 1)];
        n -= powers[pointer];
        deals ++;
    }

    if(deals > k) {
        cout << -1 << endl;
        return;
    }

    for(int i = powers.size() - 1; i > 0; i--) {
        ll l = 0;
        ll r = slots[i] + 1;
        while(l + 1 < r) {
            ll mid = (l + r) / 2;
            if((deals - mid) + mid * 3 <= k) l = mid;
            else r = mid;
        }
        deals = (deals - l) + l * 3;
        slots[i - 1] += l * 3;
        slots[i] -= l;

    }
    price = 0;
    for(int i = 0; i < powers.size() - 1; i++) {
        price += slots[i] * (powers[i + 1] + i * powers[max(0, i - 1)]);
    }
    cout << price << endl;


}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    ll i = 1;
    while(i < (1LL << 40)) {
        powers.push_back(i);
        i *= 3;
    }
    cin>>T;
    while(T--){
        solve();
        //cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}

