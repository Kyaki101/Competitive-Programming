#include <bits/stdc++.h>
#include <complex>
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
typedef complex<double> cmpl;

const int MAX = 2e5+20, MOD = 1e9+7;

double PI = numbers::pi;

vector<cmpl> fft(vector<cmpl> &p) {
    ll n = p.size();
    if(n == 1) return p;
    vector<cmpl> pEven(n / 2), pOdd(n / 2);
    for(int i = 0; i < n / 2; i++) {
        pEven[i] = p[i * 2];
        pOdd[i] = p[i * 2 + 1];
    }
    auto a = fft(pEven);
    auto b = fft(pOdd);
    vector<cmpl> ans(n);

    for(int j = 0; j < n / 2; j++) {
        cmpl w = cmpl(cos(2.0 * PI * j / n), -sin(2.0 * PI * j / n));
        ans[j] = a[j] + w * b[j];
        ans[j + n / 2] = a[j] - w * b[j];
    }
    return ans;

}

vector<cmpl> ifft(vector<cmpl> p) {
    ll n = p.size();
    
    for(auto &x : p) x = conj(x);

    p = fft(p);

    for(auto &x : p) x = conj(x);

    for(auto &x : p) x /= n;

    return p;
}

vector<ll> mult(vector<ll> &p, vector<ll> &q) {
    ll n = 1;
    while(n < (ll)p.size() + (ll)q.size() - 1) n *= 2;
    vector<cmpl> pc(n), qc(n);
    copy(ALL(p), pc.begin());
    copy(ALL(q), qc.begin());

    pc = fft(pc);
    qc = fft(qc);
    vector<cmpl> ansc(n);
    for(int i = 0; i < n; i++) {
        ansc[i] = pc[i] * qc[i];
    }

    ansc = ifft(ansc);

    vector<ll> ans(n);
    for(int i = 0; i < n; i++) {
        ans[i] = round(ansc[i].real());
    }
    return ans;

}

void solve(){        
    ll n, m;
    cin >> n;
    vll p(n);
    for(auto &i : p) cin >> i;

    cin >> m;
    vll q(m);
    for(auto &i : q) cin >> i;

    auto ans = mult(p, q);
    for(int i = 0; i < (ll)p.size() + (ll)q.size() - 1; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    
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

