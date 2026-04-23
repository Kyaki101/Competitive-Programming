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


ll v(const vector<string> &mat, vll &vert, vll &hor, vector<bool> &visV, vector<bool> &visH, ll i, bool b) {
    if(i >= (ll)visV.size()) return 0;

    if(b) {

        if(i >= (ll)visV.size() - 1) return (1LL << 30);

        if(visH[i]) return hor[i];
        visH[i] = true;
        ll ans = 0;
        if(mat[0][i] != mat[0][i + 1]) ans++;
        if(mat[1][i] != mat[1][i + 1]) ans++;
        return hor[i] = ans + min(v(mat, vert, hor, visV, visH, i + 2, true), v(mat, vert, hor, visV, visH, i + 2, false));

    }
    if(visV[i]) return vert[i];
    visV[i] = true;
    ll ans = 0;
    if(mat[0][i] != mat[1][i]) ans++;
    return vert[i] = ans + min(v(mat, vert, hor, visV, visH, i + 1, true), v(mat, vert, hor, visV, visH, i + 1, false));
}


void solve(){        
    ll n;
    cin >> n;
    vector<string> mat(2);
    cin >> mat[0] >> mat[1];
    vll vert(n);
    vll hor(n);
    vector<bool> visV(n), visH(n);
    cout << min(v(mat, vert, hor, visV, visH, 0, true), v(mat, vert, hor, visV, visH, 0, false)) << endl;


    
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

