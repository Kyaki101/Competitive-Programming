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

string popC(ll n) {
    string s;
    ll acum = 0;
    for(int i = 0; i < 60; i++) {
        if(TEST(n, i)) {
            while(acum) {
                s.PB('0');
                acum--;
            }
            s.PB('1');
        }
        else acum ++;
    }
    return s;
}

void solve(){        
    ll n;
    cin >> n;
    if(n == 0) {
        cout << "YES" << endl;
        return;
    }
    string s = popC(n);

    ll k = 0;
    while(s[k] != '1') {
        s.PB('0');
        k++; 
    }

    ll i = 0;
    ll j = (ll)s.size() - 1;
    while(i < j) {
        if(s[i] != s[j]) {
            cout << "NO" << endl;
            return;
        }
        i ++;
        j --;
    }

    if(i == j) {
        if(s[i] == '1') {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;


    
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

