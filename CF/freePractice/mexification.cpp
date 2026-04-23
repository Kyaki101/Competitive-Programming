#include <bits/stdc++.h>
#include <numeric>
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
    vll a(n);
    for(auto &i : a) cin >> i;
    sort(ALL(a));
    bool br = 0;
    vector<bool> broken(n + 1);
    vector<bool> rep(n + 1);
    ll prev = -1;
    ll mex = 0;
    for(int i = 0; i < n; i++) {
        if(br) {
            broken[a[i]] = true;
            continue;
        }
        if(a[i] == prev + 1) {
            prev = a[i];
            mex = a[i] + 1;
        } 
        else if(a[i] == prev) {
            rep[a[i]] = true;
        }
        else {
            br = true;
            broken[a[i]] = true;
        }
    }
    for(int i = 0; i < n; i++) {
        if(broken[a[i]] || rep[a[i]]) a[i] = mex;
        else a[i] = a[i];
    }

    if(k == 1) {
        cout << accumulate(ALL(a), 0LL) << endl;
        return;
    }


    sort(ALL(a));

    broken.assign(n + 1, false);
    ll stop = -1;

    prev = -1;
    bool special = false;
    for(int i = 0; i < n; i++) {
        if(a[i] != prev + 1) {
            if(i != 0 && a[i - 1] == a[i]) {
                special = true;
                stop = i - 1;
            }

            else stop = i;
            break;
        }
        prev ++;
    }

    mex = prev + 1;
    if(special) mex--;

    ll perm = 0;

    if(stop == -1) {
        cout << accumulate(ALL(a), 0LL) << endl;
        return;
    }

    for(int i = 0; i < stop; i++) {
        perm += a[i];
    }


    if(special) {
        if(!(k & 1)) {
            cout << perm + (n - stop) * (mex + 1) << endl;
            return;
        }
        cout << perm + (n - stop) * mex << endl;
        return;
    }

    if(k & 1) {
        cout << perm + (n - stop) * (mex + 1) << endl;
        return;
    }

    cout << perm + (n - stop) * mex << endl;
    
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

