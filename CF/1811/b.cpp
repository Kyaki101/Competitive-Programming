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
    ll n, a, b, x, y;
    cin >> n >> a >> b >> x >> y;

ll bruh;
    ll pp;



    if(x > n / 2) x = n - x + 1;

    if(y > n / 2) y = n - y + 1;

    if(a > n / 2) a = n - a + 1;

    if(b > n / 2) b = n - b + 1;


    bruh = min(a, b);

    pp = min(x, y);



    cout << abs(pp - bruh) << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

