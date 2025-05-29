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

struct UnionFind{
    vector<int> uf;
    void init(int n){uf.assign(n, -1);}
    int Find(int i){return (uf[i]==-1)? i : uf[i] = Find(uf[i]);}
    bool Union(int i, int j){
        bool e = Find(i)==Find(j);
        if(!e) uf[Find(i)] = Find(j);
        return e;
    }
};

void solve(){        
    ll n, m;
    cin >> n >> m;
    UnionFind uf;
    uf.init(n);
    vector<pair<ll, ll>> moves;
    for(int i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        x --;
        y --;
        uf.Union(x, y);
    }
    for(int i = 1; i < n; i++) {
        if(uf.Find(i) != uf.Find(0)) {
            moves.push_back({1, i + 1});
            uf.Union(0, i);
        }
    }
    cout << moves.size() << endl;
    for(auto i : moves) {
        cout << i.first << ' ' << i.second << endl;
    }
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

