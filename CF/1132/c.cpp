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

void solve(){        
    ll n, q;
    cin >> n >> q;
    vector<ll> painted(n + 1);
    vector<pair<ll, ll>> a(q);
    for(auto &i : a) {
        cin >> i.first >> i.second;
    }
    ll tot = 0;
    for(auto &i : a) {
        for(int j = i.first; j <= i.second; j++) {
            if(painted[j] == 0) {
                tot ++;
            }
            painted[j] ++;
        }
    }
    vector<pair<ll, ll>> val;
    ll t = 0;
    for(auto &i : a) {
        ll temp = tot;
        for(int j = i.first; j <= i.second; j++) {
            painted[j]--;
            if(painted[j] == 0) temp--;
        }
        for(int j = i.first; j <= i.second; j++) {
            painted[j]++;
        }
        val.push_back({temp, t});
        t++;
    }
    vector<pair<ll, ll>> novo;
    pair<ll, ll> chosen = {-1, -1};
    ll len = (1 << 30);
    for(auto &i : val) {
        if(i.first > chosen.first) {
            chosen = i;
        }
        else if(i.first == chosen.first && i.second - i.first < len) {
            chosen = i;
            len = i.second - i.first;
        }
    }
    for(int i = 0; i < q; i++) {
        if(chosen.second != i) novo.push_back(a[i]);
    }
    painted.assign(n + 1, 0);
    tot = 0;
    for(auto &i : novo) {
        for(int j = i.first; j <= i.second; j++) {
            if(painted[j] == 0) {
                tot ++;
            }
            painted[j] ++;
        }

    }
    val.clear();
    t = 0;
    for(auto &i : novo) {
        ll temp = tot;
        for(int j = i.first; j <= i.second; j++) {
            painted[j]--;
            if(painted[j] == 0) temp--;
        }
        for(int j = i.first; j <= i.second; j++) {
            painted[j]++;
        }
        val.push_back({temp, t});
        t++;
    }
    chosen = {-1, -1};
    len = (1 << 30);
    for(auto &i : val) {
        if(i.first > chosen.first) {
            chosen = i;
        }
        else if(i.first == chosen.first && i.second - i.first < len) {
            chosen = i;
            len = i.second - i.first;
        }
    }
    for(int i = novo[chosen.second].first; i <= novo[chosen.second].second; i++) {
        painted[i]--;
        if(painted[i] == 0) {
            tot--;
        }
    }
    for(auto &i : painted) cout << i << ' ' ;
    cout << endl;
    cout << tot << endl;
    return;
    
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

