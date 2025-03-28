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
 
    ll index = 0;
    ll steps = 0;
    vector<ll> p = {1, 2, 3};
    set<ll> vis
    while(steps < 75) {
        cout << "? "<< p[0] << ' ' << p[1] << ' ' << p[2] << endl << flush;
        ll i;
        cin >> i;
        if(vis.find(i) != vis.end()) {


            
        }
        if(i == -1) {
            cout << "! " << 1 << ' ' << 2 << ' ' << 3 << endl;
            return;
        }
        if(i == 0) {
 
            cout << "! "<< p[0] << ' ' << p[1] << ' ' << p[2] << endl << flush;
            return;
        }
        p[index] = i;
        index ++;
        index %= 3;
 
    }
}
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
