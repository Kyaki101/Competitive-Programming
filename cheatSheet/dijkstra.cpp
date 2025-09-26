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

void dijk(ll start, vector<vector<pair<ll, ll>>> & g, vector<bool> & vis, vector<ll> & dist) {
    for(int i = 1; i < g.size(); i++) {
        dist[i] = (1LL << 60);
    }
    dist[start] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, start});
    while(!q.empty()) {
        ll a = q.top().second; q.pop();
        if(vis[a]) continue;
        vis[a] = true;
        for(auto & [w, b] : g[a]) {
            if(dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                q.push({dist[b], b});
            }
        }

    }
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

