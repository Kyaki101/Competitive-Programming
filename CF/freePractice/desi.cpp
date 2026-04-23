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
    stack<ll> left, right, g1, g2;
    ll l = 0;
    

    auto good = [&]() {
        if(left.empty() && right.empty()) return false;
        if(left.empty()) {
            return g2.top() == 1;
        }
        if(right.empty()) {
            return g1.top() == 1;
        }
        return gcd(g1.top(), g2.top()) == 1;

    };

    auto remove = [&]() {
        if(left.empty()) {
            while(!right.empty()) {
                left.push(right.top());
                if(g1.empty()) g1.push(right.top());
                else g1.push(gcd(g1.top(), left.top()));
                right.pop();
                g2.pop();
            }
        }
        left.pop();
        g1.pop();

    };

    auto add = [&](ll num) {
        right.push(num);
        if(g2.empty()) g2.push(num);
        else g2.push(gcd(g2.top(), num));
    };


    ll ans = (1LL << 60);
    for(int r = 0; r < n; r++) {
        add(a[r]);
        while(good()) {
            if(!g2.empty()) DEBUG(g2.top());
            if(!g1.empty()) DEBUG(g1.top());
            cout << l << ' ' << r << endl;
            ans = min(ans, (r - l) + 1);
            remove();
            l++;
        }
    }
    cout << ans << endl;
    
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

