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
    if(n == 1 || n == 3) {
        cout << -1 << endl;
        return;
    }
    string s = "6";
    ll e = 6, o = 0;
    for(int i = 1; i < n; i++) {
        if(i & 1) o+=3;
        else e+=3;
        s.push_back('3');
    }

    if(o == e) {
        reverse(ALL(s));
        cout << s << endl;
        return;
    }

    ll index = 1;
    for(int i = 0; i < n; i++) {
        if((i & 1) && e > o) {
            s[i] = '6';
            o += 3;
        }
        else if(!(i & 1) && o > e) {
            s[i] = '6';
            e += 3;
        }

    }
    reverse(ALL(s));
    cout << s << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

