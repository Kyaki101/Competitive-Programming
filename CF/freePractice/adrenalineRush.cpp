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
    ll n;
    cin >> n;
    vll a(n);
    for(auto &i : a) cin >> i;

    vector<pair<ll, ll>> ans;
    vector<ll> temp(n);

    iota(ALL(temp), 1LL);

    for(int i = 0; i < n; i++) {
        ll j = 0;
        while(j < n - 1 && temp[j + 1] > temp[j]) {
            ans.PB({temp[j + 1], temp[j]});
            swap(temp[j], temp[j + 1]);
            j++;
        }
    }


    for(int i = 0; i < n; i++) {
        ll pos = 0;
        for(int j = 0; j < n; j++) {
            if(temp[j] == a[i]) {
                pos = j;
                break;
            }
        }

        while(pos > i) {
            ans.PB({temp[pos], temp[pos - 1]});
            swap(temp[pos], temp[pos - 1]);
            pos --;
        }
    }
    cout << ans.size() << endl;
    for(auto [x, y] : ans) {
        cout << x << ' ' << y << endl;
    }



    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
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

