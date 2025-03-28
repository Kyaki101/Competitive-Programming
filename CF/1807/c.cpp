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
    string s;
    cin >> s;
    map<char, ll> mapa;
    ll num = 1;
    for(int i = 0; i < n; i++) {
        mapa[s[i]] = num;
        num = !num;
    }
    for(int i = 1; i < n; i++) {
        if(mapa[s[i - 1]] == mapa[s[i]]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

