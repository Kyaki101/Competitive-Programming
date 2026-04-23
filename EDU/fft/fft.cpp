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

typedef complex<double> cmpl;
const double PI = numbers::pi;

cmpl calcUnit(double j, double n) {
    cmpl i(0, 1);
    return cos(2 * PI * j / n) - i * sin(2 * PI * j / n);
}

vector<cmpl> fft(vector<cmpl> &P) {
    ll n = P.size();
    if(n == 1) return P;
    vector<cmpl> ans(n);
    vector<cmpl> pEven(n / 2), pOdd(n / 2);
    for(int i = 0; i < n / 2; i++) {
        pEven[i] = P[i * 2];
        pOdd[i] = P[i * 2 + 1];
    }
    auto A = fft(pEven);
    auto B = fft(pOdd);
    for(int i = 0; i < n / 2; i++) {
        cmpl w = calcUnit(i, n);
        ans[i] = A[i] + w * B[i];
        ans[i + n / 2] = A[i] - w * B[i];
    }
    return ans;

}

vector<cmpl> ifft(vector<cmpl> pVal) {
    ll n = pVal.size();
    if(n == 1) return pVal;

    vector<cmpl> A(n / 2), B(n / 2);
    for(int i = 0; i < n / 2; i++) {
        cmpl w = calcUnit(i, n);
        A[i] = (pVal[i] + pVal[i + n / 2]) / 2.0;
        B[i] = (pVal[i] - pVal[i + n / 2]) / (2.0 * w);
    }

    auto pEven = ifft(A);
    auto pOdd = ifft(B);

    vector<cmpl> P(n);
    for(int i = 0; i < n / 2; i++) {
        P[i * 2] = pEven[i];
        P[i * 2 + 1] = pOdd[i];
    }
    return P;

}


void solve(){        
    ll n, m;
    cin >> n >> m;
    vector<cmpl> p(n), q(m);
    for(auto &i : p) cin >> i;
    for(auto &i : q) cin >> i;
    if(p.size() > q.size()) swap(p, q);
    ll sz = p.size();
    while((sz & (n - 1))) {
        p.PB(0);
        sz = p.size();
    }
    while(q.size() < p.size()) q.PB(0);
    
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

