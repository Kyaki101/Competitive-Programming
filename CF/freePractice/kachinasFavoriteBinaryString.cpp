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
    string s;
    for(int i = 0; i < n; i++) {
        s.PB('0');
    }
    auto query = [&](ll l, ll r) {
        cout << "? " << l << ' ' << r << endl;
        ll x;
        cin >> x;
        return x;
    };

    auto answer = [&](bool found) {
        if(found) {
            cout << "! " << s << endl;
            return;
        }
        cout << "! IMPOSSIBLE" << endl;
    };
    
    ll prev = query(1, n);
    if(!prev) {
        answer(false);
        return;
    }


    ll countdown = 0;
    for(int i = n - 1; i > 1; i--) {
        ll nxt = query(1, i);

        if(prev == 0) {
            if(countdown) {
                s[i] = '0';
                countdown --;
            }
            else s[i] = '1';
            continue;
        }
        if(nxt < prev) {
            s[i] = '1';
            if(nxt == 0) countdown = prev;
        }
        else s[i] = '0';
        prev = nxt;
    }
    if(prev) {
        s[0] = '0';
        s[1] = '1';
    }
    else {
        if(countdown) {
            s[1] = '0';
            countdown --;
        }
        else s[1] = '1';
        if(countdown) {
            s[0] = '0';
            countdown --;
        }
        else s[0] = '1';
    }
    answer(true);

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

