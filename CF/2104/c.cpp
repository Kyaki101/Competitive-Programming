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

void solve(){        
    ll n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    ll bCount = 0;
    for(int i = 1; i <= n; i++) {
        if(s[i] == 'B') bCount ++;
    }
    if(bCount == 1 && s[n] == 'B') {
        cout << "Alice" << endl;
        return;
    }
    if(s[n] == 'A' && s[n - 1] == 'A') {
        cout << "Alice" << endl;
        return;
    }
    if(s[n] == 'A' && s[1] == 'A') {
        cout << "Alice" << endl;
        return;
    }
    cout << "Bob" << endl;
    
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

