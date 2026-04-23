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
    vll b(ALL(a));
    sort(ALL(b));
    vector<pair<ll, ll>> ans;
    set<ll> ones;
    set<ll> twos;
    for(int i = 0; i < n; i++) {
        if(a[i] == 1) ones.insert(i);
        if(a[i] == 2) twos.insert(i);
    }

    for(int i = n - 1; i > -1; i--) {

        if(a[i] != b[i]) {
            if(a[i] == 1) {
                ll temp = *twos.begin();
                swap(a[i], a[temp]);
                ones.erase(i);
                twos.erase(temp);
                ones.insert(temp);
                ans.PB({i + 1, temp + 1});
            }
            else if(a[i] == 0) {
                ll temp = *ones.begin();
                swap(a[temp], a[i]);
                ans.PB({i + 1, temp + 1});
                ones.insert(i);
                ones.erase(temp);
                if(a[i] == b[i]) continue;
                temp = *twos.begin();
                swap(a[temp], a[i]);
                ones.erase(i);
                twos.erase(temp);
                ones.insert(temp);
                ans.PB({i + 1, temp + 1});

            }
        }
    }

    cout << ans.size() << endl;
    if(ans.size() == 0) return;
    for(const auto &[x, y] : ans) {
        cout << x << ' ' << y << endl;
    }


    
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

