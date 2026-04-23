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
    string s;
    cin >> s;
    ll rb = 0;
    ll lb = 0;
    ll ra = 0;
    ll la = 0;
    vll bruh(n, 0);
    ll mvs = 0;
    for(int i = n - 1; i > -1; i--) {
        if(s[i] == 'b') {
            bruh[i] = ra;
            mvs += ra;
        }
        else {
            ra ++;
        }
    }
    ll mini = mvs;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'b') {
            mvs -= bruh[i];
            mvs += la;
        }
        if(s[i] == 'a') {
            mini = min(mvs, mini);
            la++;
        }
    }
    bruh.assign(n, 0);
    mvs = 0;
    for(int i = n - 1; i > -1; i--) {
        if(s[i] == 'a') {
            bruh[i] = rb;
            mvs += rb;
        }
        else {
            rb ++;
        }
    }
    mini = min(mini, mvs);
    for(int i = 0; i < n; i++) {
        if(s[i] == 'a') {
            mvs -= bruh[i];
            mvs += lb;
        }
        if(s[i] == 'b') {
            mini = min(mvs, mini);
            lb ++;
        }
    }
    cout << mini << endl;
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

