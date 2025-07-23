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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    priority_queue<pair<ll, ll>> pq;
    vector<bool> chosen(n, false);
    ll mini = (1 << 30);
    ll miniC = (1 << 30);
    vector<ll> g;
    for(int i = n - 1; i > -1; i--) {
        mini = min(a[i], mini);
        if(a[i] > mini) {
            g.push_back(a[i] + 1);
            miniC = min(miniC, a[i] + 1);
            chosen[i] = true;
            while(!pq.empty() && pq.top().first > miniC) {
                g.push_back(pq.top().first + 1);
                chosen[pq.top().second] = true;
                pq.pop();
            }
            continue;
        }
        pq.push({a[i], i});
        while(!pq.empty() && pq.top().first > miniC) {
            g.push_back(pq.top().first + 1);
            chosen[pq.top().second] = true;
            pq.pop();
        }
    }
    sort(ALL(g));
    for(int i = 0; i < n; i++) {
        if(!chosen[i]) {
            cout << a[i] << ' ';
        }
    }
    for(auto i : g) {
        cout << i << ' ';
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

