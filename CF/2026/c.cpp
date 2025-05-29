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
ll n;

void solve(){        
    ll n;
    cin >> n;
    string s;
    cin >> s;
    if(n == 1) {
        cout << 1 << endl;
        return;
    }
    ll ans = 0;
    stack<ll> cola;
    for(int i = 0; i < n; i++) {
        if(n - i > n / 2 || s[i] == '0') cola.push(i + 1);
    }


    while(!cola.empty()) {

        cout << cola.top() << endl;
        ans += cola.top();
        cola.pop();
    }
    cout << ans << endl;

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

