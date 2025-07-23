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
    vector<ll> a(4);
    n--;
    a[0] = n / 4 + 1;
    a[1] = n / 4 + (n % 4 >= 1);
    a[2] = n / 4 + (n % 4 >= 2);
    a[3] = n / 4 + (n % 4 >= 3);
    if(a[0] == a[3] && a[1] == a[2]) {
        cout << "Bob" << endl;
        return;
    }
    cout << "Alice" << endl; 
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

