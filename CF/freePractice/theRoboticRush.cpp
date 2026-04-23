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
    ll n, m, k;
    cin >> n >> m >> k;
    vll a(n), b(m);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    string s;
    cin >> s;
    set<ll> spikes(ALL(b));
    map<ll, set<ll>> dead;
    vector<pair<ll, ll>> lims(n, {0, 0});
    for(int i = 0; i < n; i++) {
        auto it = spikes.lower_bound(a[i]);
        if(it != spikes.end()) {
            lims[i].second = *it - a[i];
            dead[*it - a[i]].insert(i);
        }
        if(it != spikes.begin()) {
            auto pre = it;
            pre --;
            lims[i].first = *pre - a[i];
            dead[*pre - a[i]].insert(i);
        }
    }


    ll val = 0;
    ll ans = 0;
    for(int i = 0; i < k; i++) {
        if(s[i] == 'L') val --;
        else val++;
        if(dead.find(val) == dead.end()) {
            cout << n - ans << ' ';
            continue;
        }
        auto it = dead[val].begin();
        while(it != dead[val].end()) {
            ans++;
            ll e = *it;
            if(lims[e].first != 0) {
                if(lims[e].first == val) it = dead[lims[e].first].erase(it);
                else dead[lims[e].first].erase(e);
            }
            if(lims[e].second != 0) {
                if(lims[e].second == val) it = dead[lims[e].second].erase(it);
                else dead[lims[e].second].erase(e);
            }
        }

        dead.erase(val);
        cout << n - ans << ' ';
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

