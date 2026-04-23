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
    vector<string> a(n);
    for(auto &i : a) cin >> i;
    map<char, ll> mapa;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < (int)a[i].size(); j++) {
            mapa[a[i][j]] ++;

        }
    }
    for(auto word : a) {
        map<char, ll> temp;
        for(auto letter : word) {
            temp[letter] ++;
            mapa[letter] --;
        }
        ll maxi = 0;
        for(auto [x, y] : temp) {
            if(mapa[x] == 0) {
                maxi = 1 << 30;
                continue;
            }
            maxi = max((y + (mapa[x] - 1)) / mapa[x], maxi);
        }

        for(auto letter : word) {
            mapa[letter] ++;
        }

        if(maxi > m) {
            cout << -1 << ' ';
            continue;
        }
        cout << m - maxi << ' '; 

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

