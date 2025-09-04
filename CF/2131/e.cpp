#include <bits/stdc++.h>
using namespace std;

#define SET(m,i) ((m)|(1ULL<<(i)))
#define TEST(m,i) ((m)&(1ULL<<(i)))
#define CLEAR(m,i) ((m)&~(1ULL<<(i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define DEBUG_ALL(a) for(auto &w:a)cout<<w<<' ';cout<<endl;
#define ALLN(x,n) begin(x), begin(x)+n
#define ALL(x) begin(x), end(x)
#define vec vector
#define snd second
#define fst first
#define pb push_back
#define ll long long
const ll MAX = 2e5+20, MOD = 1e9+7;

void solve(){        
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    if(a[n - 1] != b[n - 1]) {
        cout << "NO" << endl;
        return;
    }
    vector<ll> c(ALL(a));
    for(int i = n - 2; i > -1; i--) {
        if(a[i] == b[i]) {
            continue;
        }
        else if((a[i] ^ a[i + 1]) == b[i]) {
            
            c[i] ^= a[i + 1];


        }
    }



    for(int i = n - 2; i > -1; i--) {
        if(c[i] == b[i]) {
            continue;
        }
        else if((a[i] ^ c[i + 1]) == b[i]) {
            
            c[i] ^= c[i + 1];

        }
    }
    for(int i = 0; i < n; i++) {
        if(c[i] != b[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
        //cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}

