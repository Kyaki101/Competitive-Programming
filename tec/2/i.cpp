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
    ll l = 0;
    ll r = n - 1;
    pair<ll, ll> prev = {a[0], a[r]};
    bool dir = false;
    if(a[0] > a[r]) dir = false;
    else dir = true;
    l++; r--;

    while(l < r) {
        cout << l << ' ' << r << endl;
        if(dir) {
            if(max(prev.first, prev.second) > max(a[l], a[r])) {
                if(a[l] < a[r]) {
                    cout << "LR";
                }
                else {
                    cout << "RL";
                }
                dir = true;
            }
            else {
                if(a[l] > a[r]) {
                    cout << "LR" ;
                }
                else {
                    cout << "RL" ;
                }
                dir = false;
            }
            prev = {a[l], a[r]};
            r--;
            l++;
            continue;
        }
        if(min(prev.first, prev.second) > max(a[l], a[r])) {
            if(a[l] < a[r]) {
                cout << "LR";
            }
            else {
                cout << "RL";
            }
            dir = true;

        }
        else {
            if(a[l] > a[r]) {
                cout << "LR";
            }
            else cout << "RL";
            dir = false;

        }
        prev = {a[l], a[r]};
        r --;
        l++;
    }
    if(l == r) cout << "L";
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

