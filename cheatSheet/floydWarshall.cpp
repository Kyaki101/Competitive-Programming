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

void fwarsh(vector<vector<ll>> & g, vector<vector<ll>> & dist) {
    for(int i = 1; i < g.size(); i++) {
        for(int j = 1; j < g.size(); j++) {
            if(i == j) dist[i][j] = 0;
            else if(g[i][j]) dist[i][j] = g[i][j];
            else dist[i][j] = (1LL << 30);
        }
    }
    for(int k = 1; k < g.size(); k++) {
        for(int i = 1; i < g.size(); i++) {
            for(int j = 1; j < g.size(); j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}



signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    return 0;
}

