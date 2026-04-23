#include <bits/stdc++.h>
#include <queue>
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
    ll n, m;
    cin >> n >> m;
    vll a(n), b(m);
    for(auto &i : a) cin >> i; 
    for(auto &i : b) cin >> i; 
    priority_queue<ll> as, bs;
    for(auto i : a) as.push(i);
    for(auto i : b) bs.push(i);
    ll turn = 1;
    auto elim = [](priority_queue<ll> & a, priority_queue<ll> & b) {
        if(a.top() >= b.top()) {
            b.pop();
        }
        else {
            ll temp = b.top();
            b.pop();
            temp -= a.top();
            b.push(temp);
        }

    };
    while(!as.empty() && !bs.empty()) {
        if(turn & 1) {
            elim(as, bs);
        }
        else {
            elim(bs, as);
        }
        turn ++;
    }
    if(as.empty()) {
        cout << "Bob" << endl;
        return;
    }
    cout << "Alice" << endl;
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

