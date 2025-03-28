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

set<char> c;

void solve(){        
    char a;
    cin >> a;
    if(c.find(a) == c.end()) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
        
 }

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s = "codeforces";
    for(auto i : s) c.insert(i);


    cin>>t;
    while(t--){
        solve();
    }return 0;
}

