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




long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b; // Avoids overflow better than (a * b) / gcd(a, b)
}

void solve(){        
    ll n;
    cin >> n;
    ll b = lcm(3, 5);
    if(n == 0) {
        cout << 1 << endl;
        return;
    }
    if(n == 1) {
        cout << 2 << endl;
        return;
    }
    cout << (n / b * 3) + (min(n % b + 1, 3LL))<< endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

