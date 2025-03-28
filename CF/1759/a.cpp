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
    string a = "Yes";    

    string b;
    cin >> b;
    ll n = b.size();

    ll index = 0;
    if(b[0] == 'e') {
        index = 1;

    }
    else if(b[0] == 's') {
        index = 2;
    }
    else if(b[0] != 'Y') {
        cout << "NO" << endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        if(b[i] != a[index]) {
            cout << "NO" << endl;
            return;
        }
        index ++;
        index %= 3;
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

