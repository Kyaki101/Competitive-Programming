#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<'\n'
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
ll t=1, n, k;

void solve(){        
    cin>>n>>k;
    if(k % 2 == 0 || (n % k) % 2 == 0) {
        cout << n % k << endl;
        return;
    }
    if((n % k) % 2 != 0) {
        ll res = 1;
        ll b = n;
        b -= k;
        res += 2 * (b / (k * 2));
        cout << n % (k * res) << endl;


        return;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    while(t--){
        solve();
    }return 0;
}

