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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vll a(n);
    for(auto &i : a) cin >> i;
    ll first = -1;
    ll z = 0;
    for(int i = n - 1; i > -1; i--) {
        if(s[i] == '0') {
            first = i;
            z ++;
        }
    }

    ll curr = 0;
    ll maxi = 0;
    ll god = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            curr = 0;
            maxi = 0;
            continue;
        }
        curr += a[i];
        curr = max(0LL, curr);
        maxi = max(curr, maxi);
        god = max(maxi, god);
    }
    if(god > k) {
        cout << "NO" << endl;
        return;
    }

    maxi = 0;
    curr = 0;
    for(int i = 0; i < n; i++) {
        curr += a[i];
        curr = max(0LL, curr);
        maxi = max(maxi, curr);
    }
    auto kadan = [&]() {
        ll best = 0;
        ll c = 0;
        for(int i = 0; i < n; i++) {
            c += a[i];
            c = max(0LL, c);
            best = max(best, c);
        }
        return best;
    };

    if(first == -1) {
        if(kadan() == k) {
            cout << "YES" << endl;
            for(auto i : a) cout << i << ' ';
            cout << endl;
            return;
        }
        cout << "NO" << endl;
        return;
    }



    for(int i = 0; i < n; i++) {
        if(i == first) continue;
        if(s[i] == '0') a[i] = -1 * 10000000000000000LL;
    }

    ll l = -1000000000000LL;
    ll r = 1000000000001LL;
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        a[first] = mid;
        if(kadan() <= k) l = mid;
        else r = mid;
        a[first] = l;
    }
    if(kadan() != k) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for(auto i : a) cout << i << ' ';
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

