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
    vll a(n), b(n);
    for(auto &i : a) cin >> i;
    for(auto &i: b) cin >> i;
    vector<pair<ll, ll>> al(n), bob(n);
    vector<bool> vis(n, false);
    for(int i = 0; i < n; i++) {
        al[i].first = (a[i] - 1) + b[i];
        bob[i].first = (b[i] - 1) + a[i];
        al[i].second = i;
        bob[i].second = i;
    }
    sort(bob.rbegin(), bob.rend()); sort(al.rbegin(), al.rend());
    ll i = 0, j = 0;
    ll turn = 0;
    ll acount = 0, bcount = 0;
    while(i < n && j < n) {
        if(turn & 1) {
            while(j < n && vis[bob[j].second]) {
                j++;
            }
            if(j < n) {
                bcount += b[bob[j].second] - 1;
                vis[bob[j].second] = true;
            }
        }
        else {
            while(i < n && vis[al[i].second]) {
                i++;
            }
            if(i < n) {
                acount += a[al[i].second] - 1;
                vis[al[i].second] = true;
            }
        }
        turn ++;

    }
    cout << acount - bcount << endl;
    
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

