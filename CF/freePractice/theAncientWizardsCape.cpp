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
    if(n == 1) {
        cout << 2 << endl;
        return;
    }
    bool first = true;
    bool second = true;;
    vector<int> dir(n);

    auto fun = [&](bool& turn) {
        for(int i = 1; i < n - 1; i++) {
            if(abs(a[i + 1] - a[i]) >= 2) {
                turn = 0;
                return;
            }
            if(a[i + 1] == a[i]) {
                if(dir[i] == 1) dir[i + 1] = -1;
                else dir[i + 1] = 1;
            }
            if(a[i + 1] < a[i]) {
                if(dir[i] == -1) {
                    turn = false;
                    return;
                }
                dir[i + 1] = 1;
            }
            if(a[i + 1] > a[i]) {
                if(dir[i] == 1) {
                    turn = false;
                    return;
                }
                dir[i + 1] = -1;
            }
        }
        vll pref(n);
        vll suff(n);
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i - 1];
            if(dir[i - 1] == 1) pref[i] ++;
        }

        for(int i = n - 2; i > -1; i--) {
            suff[i] = suff[i + 1];
            if(dir[i + 1] == -1) suff[i] ++;
        }




        for(int i = 0; i < n; i++) {
            if(pref[i] + suff[i] != n - a[i]) turn = false;
        }


    };


    if(a[0] == a[1]) {
        dir[0] = -1;
        dir[1] = 1;
        fun(first);

        dir[0] = 1;
        dir[1] = -1;

        fun(second);
        cout << first + second << endl;
        return;
    }

    if(a[0] < a[1]) {
        dir[0] = -1;
        dir[1] = -1;
    }
    else {
        dir[0] = 1;
        dir[1] = 1;
    }
    fun(first);
    cout << first << endl;


    
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

