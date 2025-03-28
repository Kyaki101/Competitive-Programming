#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define ll double
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;


void topSort(long long node, vector<vector<pair<ll, ll> > > & g, vector<ll> & list, vector<bool> & vis) {
    vis[node] = true;
    for(auto i : g[node]) {
        if(!vis[i.first]) topSort(i.first, g, list, vis);
    }
    list.push_back(node);
}


bool shortest(vector<vector<pair<ll, ll> > > & g, vector<ll> & dist, vector<ll> & topo, vector<ll> & parents, ll x) {
    for(auto node : topo) {
        for(auto i : g[node]) {
            if(dist[node] + (i.second - x) < dist[i.first]) {
                parents[i.first] = node;
                dist[i.first] = dist[node] + (i.second - x);
            }
        }

    }

    if(dist[g.size() - 1] <= 0) {
        return true;
    }

    return false;
    
}

void solve(){        
    int n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll> > > g(n);

    for(int i = 0; i < m; i++) {
        long long a, b;
        double w;
        cin >> a >> b >> w;
        a --;
        b --;
        g[a].push_back({b, w});
    }

    vector<ll> topo;
    vector<bool> vis(n, false);
    topSort(0, g, topo, vis);
    reverse(ALL(topo));

    vector<ll> parents(n, 0);

    vector<ll> dist(n, (1 << 30));



    ll r = 1000;
    ll l = -1;
    vector<ll> ans;
    long long count = 0;
    while(count < 100) {

        count ++;
        parents.assign(n, 0);
        dist.assign(n, (1 << 30));
        dist[0] = 0;


        ll mid = (r + l) / 2;
        if(shortest(g, dist, topo, parents, mid)) {
            r = mid;
            ans.clear();
            ll pointer = n - 1;
            while(pointer != parents[pointer]) {
                ans.push_back(pointer + 1);
                pointer = parents[pointer];

            }
        }
        else l = mid;

    }



    ans.push_back(1);
    reverse(ALL(ans));
    cout << ans.size() - 1 << endl;
    for(auto i : ans) {
        cout << i << ' ';
    }
    cout << endl;



}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}

