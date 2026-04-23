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
    ll n, h, k;
    cin >> n >> h >> k;
    vll a(n);
    for(auto &i : a) cin >> i;
    ll round = accumulate(ALL(a), 0LL);
    ll time = 0;
    ll rem = round * (h / round);
    time += n * (h / round);
    if(h % round == 0) {
        time += k * (h / round - 1);
    }
    else time += k * (h / round);
    h -= rem;
    if(h == 0) {
        cout << time << endl;
        return;
    }
    vll acum(n);
    partial_sum(ALL(a), acum.begin());
    vll prefMin(n);
    vll suffMax(n);
    prefMin[0] = a[0];
    suffMax[n - 1] = a[n - 1];

    for(int i = 1; i < n; i++) {
        prefMin[i] = min(prefMin[i - 1], a[i]);
    }
    for(int i = n - 2; i > -1; i--) {
        suffMax[i] = max(suffMax[i + 1], a[i]);
    }
    for(int i = 0; i < n - 1; i++) {
        ll bruh = acum[i];
        if(bruh - prefMin[i] + suffMax[i + 1] >= h || bruh >= h) {
            cout << time + i + 1 << endl;
            return;
        }
    }
    cout << time + n << endl;
    

    
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

