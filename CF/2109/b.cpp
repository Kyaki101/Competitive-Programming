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


ll vert(ll top, ll bottom, ll a) {
    ll count = 0;
    while(top != bottom) {
        if(bottom - a < a - top) {
            top = a;
        }
        else bottom = a;
        count ++;
        a = (top + bottom) / 2;
    }
    return count;

}
ll hor(ll left, ll right, ll b) {
    ll count = 0;
    while(left != right) {
        if(right - b < b - left) {
            left = b;
        }
        else right = b;
        count ++;
        b = (right + left) / 2;
    }
    return count;

}


void solve(){        
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    ll top = 1;
    ll bottom = n;
    ll left = 1;
    ll right = m;
    bool turn = true;
    ll count = 0;
    ll x, y;
    x = vert(top, bottom, a);
    if(x == 0) {
        x += hor(left, right, b);
    }
    else x += hor(left, right, (left + right) / 2);
    y = hor(left, right, b);
    if(y == 0) {
        y += vert(top, bottom, a);
    }
    else y += vert(top, bottom, (top + bottom) / 2);
    cout << min(x, y) << endl;


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

