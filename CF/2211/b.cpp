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

vll sieve(200010, 0);

void solve(){        
    ll x, y;
    cin >> x >> y;

    ll sum = abs(x - y);

    auto msb = [&](ll num) {
        ll index = 0;
        for(int i = 0; i < 60; i++) {
            if(TEST(num, i)) {
                index = i;
            }
        }
        return index;
    };

    if(sum == 0) {
        cout << 1 << endl;
        for(int i = 0; i < x; i++) {
            cout << 1 << ' ';
        }
        for(int i = 0; i < y; i++) {
            cout << -1 << ' ';
        }
        cout << endl;
        return;
    }


    cout << sieve[abs(x - y)] << endl;
    for(int i = 0; i < x; i++) {
        cout << 1 << ' ';
    }
    for(int i = 0; i < y; i++) {
        cout << -1 << ' ';
    }
    cout << endl;



    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    for(int i = 1; i < 200010; i++) {
        for(int j = i; j < 200010; j += i) {
            sieve[j] ++;
        }
    }

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

