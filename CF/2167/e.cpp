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
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    sort(ALL(a));
    set<ll> pos;
    priority_queue<vll> pq;
    for(int i = 0; i < n - 1; i++) {
        vector<ll> bruh(4);
        bruh[1] = (a[i + 1] + a[i]) / 2;
        bruh[0] = min(abs(a[i] - bruh[1]), abs(a[i + 1] - bruh[1]));
        bruh[2] = a[i];
        bruh[3] = a[i + 1];
        pq.push(bruh);
    }
    vector<ll> fafo(4);
    fafo[1] = (0);
    fafo[0] = a[0];
    fafo[2] = -1;
    fafo[3] = a[0];
    pq.push(fafo);
    fafo[1] = x;
    fafo[0] = x - a[n - 1];
    fafo[2] = a[n - 1];
    fafo[3] = x + 1;
    pq.push(fafo);
    vector<ll> ans;
    while(k --) {
        auto v = pq.top();
        pq.pop();
        if(pos.find(v[1]) == pos.end()) {
            ans.PB(v[1]);
            pos.insert(v[1]);
        }
        else {
            k++;
            continue;
        }
        if(v[2] == -1) {
            auto w = v;
            w[1] = v[1] + 1;
            w[0] = v[0] - 1;
            if(w[0] >= 0) {
                pq.push(w);
            }

            continue;
        }
        if(v[3] == x + 1) {
            auto w = v;
            w[1] = v[1] - 1;
            w[0] = v[0] - 1;
            if(w[0] >= 0) {
                pq.push(w);
            }
            continue;
        }

        if(v[0] != 0) {
            if(v[1] + 1 <= n - 1 && pos.find(v[1] + 1) == pos.end()) {
                auto w = v;
                w[1] = v[1] + 1;
                w[0] = min(abs(w[2] - w[1]), abs(w[3] - w[1]));
                pq.push(w);
            }
            if(v[1] - 1 >= 0 && pos.find(v[1] - 1) == pos.end()) {
                auto w = v;
                w[1] = v[1] - 1;
                w[0] = min(abs(w[2] - w[1]), abs(w[3] - w[1]));
                pq.push(w);
            }
        }

    }
    for(auto i : ans) {
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

