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


bool lookUp(vector<vector<ll> > & mat, char c) {
    DEBUG(c);
    for(int i = 0; i < 26; i++) {
        if(mat[c - 97][i] > 0) {
            mat[c - 97][i] --;
            return i + 97;
        }

    }
    return false;
}

void solve(){        
    
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<ll> > mat(26, vector<ll>(26, 0));
    for(int i = 0; i < n; i++) {

        for(int j = 0; j < 26; j++) {
            if(j + 97 != s[i]) {
                mat[j][s[i] - 97] ++;
            }
        }
    }
    ll ans = 0;

    multiset<ll> used;

    for(int i = 0; i < n; i++) {
        if(s[i] == s[(n - 1) - i]) {
            if(used.find(s[i]) != used.end()) {
                used.erase(used.find(s[i]));
                continue;
            }
            char b = lookUp(mat, s[i]);
            if(b == 'A') {
                cout << -1 << endl;
                return;
            }
            ans ++;
            s[i] = 'A';
            used.insert(b);
        }
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

