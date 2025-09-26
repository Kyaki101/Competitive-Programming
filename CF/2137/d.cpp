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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    map<ll, ll> first;
    for(auto i : a) first[i] ++;

    for(auto i : first) {
        if(i.second % i.first != 0) {
            cout << -1 << endl;
            return;
        }
    }
    map<ll, queue<ll>> mapa;
    ll curr = 0;
    for(auto i : first) {
        for(int j = 0; j < i.second; j++) {
            if(j % i.first == 0) {
                curr ++;
            }
            mapa[i.first].push(curr);
        }
    }
    for(auto i : a) {
        cout << mapa[i].front() << ' ';
        mapa[i].pop();
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

