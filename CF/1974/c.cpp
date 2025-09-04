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

void solve(){        
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    map<vector<ll>, ll> mapa;
    for(int i = 2; i < n; i++) {
        vector<ll> temp;
        temp.push_back(a[i - 2]);
        temp.push_back(a[i - 1]);
        temp.push_back(a[i]);
        mapa[temp] ++;
    }

    map<vector<ll>, ll> matches;
    auto it = mapa.begin();
    ll ans = 0;
    while(it != mapa.end()) {
        for(int i = 0; i < 3; i++) {
            vector<ll> temp;
            for(int j = 0; j < 3; j++) {
                if(i == j) temp.push_back(0);
                else temp.push_back(it->first[j]);
            }
            ans += matches[temp] * it->second;
            matches[temp] += it->second;
        }
        it++;
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
        //cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}

