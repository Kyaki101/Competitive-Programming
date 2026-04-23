#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define F second
#define S first
#define PB push_back
#define ll long long
typedef vector<ll> vll;

const int MAX = 2e5+20, MOD = 1e9+7;

void solve(){        
    ll x, n, m;
    cin >> x >> n >> m;
    ll temp = x;
    ll bruh = n;
    while(temp && bruh) {
        temp /= 2;
        bruh --;
    }
    if(temp == 0) {
        cout << 0 << ' ' << 0 << endl;
        return;
    }
    ll fish = m;

    while(temp > 1 && fish) {
        temp = (temp + 1) / 2;
        fish --;
    }
    ll maxi = temp;
    temp = x;
    while(temp > 1 && m) {
        temp = (temp + 1) / 2;
        m --;
    }
    while(temp && n) {
        temp /= 2;
        n--;
    }
    cout << temp << ' ' << maxi << endl;
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        #ifdef ICPC 
            cout << "--------------------------------------------------" << endl;
        #endif // 
    }
    #ifdef ICPC 
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}

