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
ll n;


bool isPrime(ll n) {
    if(n == 1) return false;
    ll i = 2;
    while(i * i <= n) {
        if(n % i == 0) return false;
        i++;
    }
    return true;
}

void solve(){        
    ll n, k;
    cin >> n >> k;

    if(n == 1 && k == 2) {
        cout << "YES" << endl;
        return;
    }
    if(isPrime(n) && k == 1) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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

