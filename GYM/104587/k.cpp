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
    ll n, m;
    cin >> n >> m;
    if(n == 1) {
        cout << 1 << ' ' << 1 << endl;
        return;
    }
    if(m == 1) {
        cout << n << ' ' << 1 << endl;
        return;
    }
    map<ll, pair<ll, ll>> mapa;

    for(int i = 1; i <= n; i++) {
        ll avail = m;
        ll ans = 0;
        if(i <= n / 2) {
            ll bot = i;
            ll top = n;
            while(avail > 1 && top > bot) {
            DEBUG(bot);
            DEBUG(top);
                ll mid = (bot + top + 1) / 2;
                bot = mid;
                ans ++;
                avail --;
            }
            ans += top - bot;
        }
        else {
            ll bot = 0;
            ll top = i;
            while(avail > 1 && top > bot) {
                ll mid = (bot + top) / 2;
                top = mid;
                ans ++;
                avail --;
            }
            ans += top - bot;
        }
        if(mapa.find(ans) == mapa.end()) {
            mapa[ans] = {i, i};
            continue;
        }
        mapa[ans].first = min(mapa[ans].first, (ll)i);
        mapa[ans].second = max(mapa[ans].second , (ll)i);
    }

    ll num = (*mapa.begin()).first;
    if(mapa[num].first == mapa[num].second) {
        cout << num << ' ' << mapa[num].first << endl;
        return;
    }
    cout << num << ' ' << mapa[num].first << '-' << mapa[num].second << endl;


    
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

