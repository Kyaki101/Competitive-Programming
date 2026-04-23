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

vector<vll> sieve(50001);

void solve(){        
    ll n, k;
    cin >> n >> k;

    vector<string> a(k);
    for(auto &i : a) cin >> i;

    map<ll, set<ll>> mapa;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n; j++) {
            mapa[j].insert(a[i][j]);
        }
    }


    for(auto d : sieve[n]) {
        vector<set<char>> bruh(d);
        for(int j = 0; j < d; j++) {
            for(int i = 0; i < k; i++) {
                bruh[j].insert(a[i][j]);
            }
        }


        for(int w = 0; w < d; w++) {
            for(int j = w; j < n; j += d) {
                set<char> temp;
                for(int i = 0; i < k; i++) {
                    if(bruh[w].find(a[i][j]) != bruh[w].end()) temp.insert(a[i][j]);
                }
                bruh[w] = temp;
            }
        }
        bool check = true;
        for(int i = 0; i < d; i++) {
            if(!bruh[i].size()) {
                check = false;
                break;
            }
        }

        if(check) {
            for(int j = 0; j < n / d; j++) for(int i = 0; i < d; i++) {
                cout << (*bruh[i].begin());
            }
            cout << endl;
            return;
        }

        

    }

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    for(int i = 1; i < 50001; i++) sieve[i].PB(1);
    for(int i = 2; i < 50001; i++) {
        for(int j = i; j < 50001; j += i) sieve[j].PB(i);
    }
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

