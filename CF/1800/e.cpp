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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string t;
    cin >> t;

    string tC, sC;
    tC = t, sC = s;
    sort(ALL(tC)), sort(ALL(sC));
    if(tC != sC) {
        cout << "NO" << endl;
        return;
    }

    if(s == t || n - k > 1) {
        cout << "YES" << endl;
        return;
    }

    if(n - k == 1) {
        swap(t[0], t[n - 1]);
        if(s == t) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;


}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

