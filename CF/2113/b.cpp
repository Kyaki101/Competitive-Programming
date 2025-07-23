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
    ll w, h, a, b;
    cin >> w >> h >> a >> b;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    bool hor = false, vert = false;
    if(y1 < y2 && y1 + b > y2 || y2 < y1 && y2 + b > y1) {
        hor = true;

        cout << y1 + b<< endl;
    }
    if(x1 < x2 && x1 + a > x2 || x2 < x1 && x2 + a > x1) {
        vert = true;
    }
    
    if(hor) {
        ll dist;
        if(x1 < x2) {
            dist = x2 - (x1 + a);
            
        }
        else dist = x1 - (x2 + a);
        if(dist < a) {
            cout << "NO" << endl;
            return;
        }
    }
    if(vert) {
        ll dist;
        if(y1 < y2) {
            dist = y2 - (y1 + b);
        }
        else dist = y1 - (y2 + b);
        if(dist < b) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;

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

