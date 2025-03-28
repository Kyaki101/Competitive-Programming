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
    ll n, x, k;
    cin >> n >> x >> k;
    string s;
    cin >> s;
    bool reached = false;
    ll index = 0;
    while(x != 0 && index < n) {
        if(s[index] == 'L') x--;
        else x++;
        if(x == 0) reached = true;
        k --;



        index ++;

    }
    if(!reached) {
        cout << 0 << endl;
        return;
    }
    ll cycleTime = 0;
    reached = false;
    index = 0;

    while(!reached && index < n) {
        cycleTime ++;
        if(s[index] == 'L') x--;
        else x ++;
        if(x == 0) reached = true;
        index ++;
    }
    if(!reached) {
        cout << 1 << endl;
        return;
    }

    cout << k/cycleTime + 1 << endl;
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

