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

vll primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

void solve(){        
    ll n;
    cin >> n;
    vll a(n), b(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;

    vector<bool> ans(n);

    auto lcm = [&](ll x, ll y) {
        return (x * y) / gcd(x, y);
    };
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            if(gcd(a[i], a[i + 1]) != a[i] && gcd(a[i], a[i + 1]) <= b[i]) {
                ans[i] = true;
                a[i] = gcd(a[i], a[i + 1]);

            }
            continue;
        }
        if(i == n - 1) {
            if(gcd(a[i], a[i - 1]) != a[i] && gcd(a[i], a[i - 1]) <= b[i]) {
                ans[i] = true;
                a[i] = gcd(a[i], a[i - 1]);
            }
            continue;
        }
        ll l = gcd(a[i], a[i - 1]);
        ll r = gcd(a[i], a[i + 1]);
        ll bruh = lcm(l, r);
        if(bruh <= b[i] && bruh != a[i]) {
            ans[i] = true;
            a[i] = bruh;
        }
    }


    vector<set<ll>> opts(n);
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            ll r = gcd(a[i], a[i + 1]);
            if(!ans[i]) for(auto p : primes) {
                ll bruh = p * a[i];
                if(gcd(bruh, a[i + 1]) == r && bruh <= b[i]) {
                    opts[i].insert(p);
                }
            }
            continue;

        }
        if(i == n - 1) {
            ll l = gcd(a[i], a[i - 1]);
            if(!ans[i]) for(auto p : primes) {
                ll bruh = p * a[i];
                if(gcd(bruh, a[i - 1]) == l && bruh <= b[i]) {
                    opts[i].insert(p);
                }
            }
            continue;
        }

        ll l = gcd(a[i], a[i - 1]);
        ll r = gcd(a[i], a[i + 1]);
        if(!ans[i]) for(auto p : primes) {
            ll bruh = p * a[i];
            if(gcd(bruh, a[i - 1]) == l && gcd(bruh, a[i + 1]) == r && bruh <= b[i]) {
                opts[i].insert(p);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(opts[i].size() == 1) {
            ll num = *opts[i].begin();
            if(i > 0) {
                if(opts[i - 1].find(num) != opts[i - 1].end()) opts[i - 1].erase(num);
            }
            if(i < n - 1) {
                if(opts[i + 1].find(num) != opts[i + 1].end()) opts[i + 1].erase(num);
            }
        }
        else if(opts[i].size() == 0) continue;

        ans[i] = true;

    }

    ll res = 0;

    for(auto i : ans) {
        res += i;
    }

    cout << res << endl;


    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    reverse(ALL(primes));
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

