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
    string bruh = "aa", hm = "bb";
    if(n % 2 == 0) {
        for(int i = 0; i < n - 1; i++) {
            string temp = s.substr(i, 2);
            if(i % 2 == 0 && (temp == bruh || temp == hm)) {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
        return;
    }
    if(s[0] == 'b') {
        cout << "NO" << endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        string temp = s.substr(i, 2);
        if((i & 1) && (temp == bruh || temp == hm)) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        #ifdef ICPC 
            cout << "--------------------------------------------------" << endl;
        #endif // 
    }
    #ifdef ICPC 
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}

