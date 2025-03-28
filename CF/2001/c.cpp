#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
typedef long long int ll;
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

void solve(){        
    ll n;
    cin >> n;
    set<ll> vis;
    set<pair<ll, ll> > edges;
    set<pair<ll, ll> > queries;
    for(int i = 2; i <= n; i++) {
        ll node = i;
        if(vis.find(node) == vis.end()) {
            stack<ll> pila;
            pila.push(node);
            ll pre = 1;
            while(!pila.empty()) {
                node = pila.top();
                if(vis.find(node) != vis.end()) {
                    pre = node;
                    pila.pop();
                    node = pila.top();
                }
                ll x;

                cout << '?' << ' ' << pre << ' ' << node << endl; 
                queries.insert({pre, node});

                cin >> x;
                if(x == pre) {
                    edges.insert({pre, node});
                    vis.insert(node);
                    pre = pila.top();
                    pila.pop();
                }
                else pila.push(x);
            }
        }
    }

    cout << "! ";

    for(auto i : edges) {
        cout << i.first << ' ' << i.second << ' ';
    }
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

