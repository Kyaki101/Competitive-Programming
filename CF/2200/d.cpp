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
    ll n, x, y;
    cin >> n >> x >> y;
    vll a(n);
    for(auto &i : a) cin >> i;
    vll out;
    vll in;
    for(int i = 0; i < x; i++) {
        out.PB(a[i]);
    }
    for(int i = y; i < n; i++) {
        out.PB(a[i]);
    }
    ll mini = (1 << 30);
    ll index = 0;
    for(int i = x; i < y; i++) {
        in.PB(a[i]);
        if(a[i] < mini) {
            index = in.size() - 1;
            mini = a[i];
        }
    }
    vll temp;
    temp.PB(in[index]);
    ll bruh = in.size();

    for(int i = (index + 1) % bruh; i != index; i = (i + 1) % bruh) {
        temp.PB(in[i]);
    }


    in = temp;


    ll hm = out.size();
    ll i = 0; 
    ll j = 0;
    vll ans;
    while(j < hm && out[j] < in[i]) {
        ans.PB(out[j]);
        j++;
    }
    for(auto k : in) ans.PB(k);

    while(j < hm) {
        ans.PB(out[j]);
        j++;
    }
    for(auto k : ans) {
        cout << k << ' ';
    }
    cout << endl;



    
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

