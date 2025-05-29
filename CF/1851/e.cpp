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


ll mixer(ll index, vector<vector<ll>> & recipies, vector<ll> & a, vector<ll> & mix) {
    if(mix[index] != -1) {
        return mix[index];
    }

    mix[index] = 0;
    for(int i = 0; i < recipies[index].size(); i++) {
        ll nxt = mixer(recipies[index][i], recipies, a, mix);
        // cout << a[recipies[index][i]] << ' ' << nxt << endl;
        mix[index] += min(a[recipies[index][i]], nxt);
        
    }
    return mix[index];

}

void solve(){        
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    vector<ll> owned(k);
    for(auto &i : owned) {
        cin >> i;
        i --;
    }

    vector<vector<ll>> recipies(n);
    for(int i = 0; i < n; i++) {
        ll m;
        cin >> m;
        for(int j = 0; j < m; j++) {
            ll x;
            cin >> x;
            x --;
            recipies[i].push_back(x);
        }
    }
    vector<ll> mix(n, -1);

    for(int i = 0; i < k; i++) {
        mix[owned[i]] = 0;
    }

    for(int i = 0; i < n; i++) {
        if(mix[i] == 0) continue;
        if(recipies[i].size() == 0) {
            mix[i] = a[i];
        }
    }

    for(int i = 0; i < n; i++) {
        mix[i] = mixer(i, recipies, a, mix);
    }

    cout << endl;
    for(int i = 0; i < n; i++) {
        cout << min(mix[i], a[i]) << ' ';
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
    }return 0;
}

