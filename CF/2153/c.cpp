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
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> mapa;
    for(auto &i : a) {
        cin >> i;
        mapa[i] ++;
    }
    vector<ll> alone;
    vector<ll> together;
    for(auto i : mapa) {
        if(i.second & 1) {
            alone.PB(i.first);
            i.second --;
        }
        while(i.second) {
            together.PB(i.first);
            i.second -= 2;
        }
    }

    ll totLen = 0;
    for(auto i : together) totLen += 2 * i;
    sort(alone.rbegin(), alone.rend());

    if(totLen == 0) {
        cout << 0 << endl;
        return;
    }

    ll s = alone.size();
    ll maxi = totLen;
    if(together.size() == 1) {
        maxi = 0;
    }
    for(int i = 0; i < s - 1; i++) {
        if(alone[i + 1] + totLen > alone[i]) {
            maxi = max(totLen + alone[i] + alone[i + 1], maxi); 
        }

    }
    for(int i = 0; i < s; i++) {
        if(totLen > alone[i]) {
            maxi = max(totLen + alone[i], maxi);
        }
    }
    cout << maxi << endl;


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

