#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define pb push_back
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;

void solve(){        
    ll n;
    char light;
    cin >> n >> light;
    string s;
    cin >> s;
    string full = s + s;
    if(light == 'g') {
        cout << 0 << endl;
        return;
    }
    ll maxi = 0;
    ll curr = 0;
    bool on = false;
    for(int i = 0; i < 2 * n; i++) {
        if(full[i] == light && !on) {
            on = true;

        }
        if(full[i] == 'g') {
            maxi = max(curr, maxi);
            curr = 0;
            on = false;
        }
        if(on) curr ++;
    }
    cout << maxi << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

