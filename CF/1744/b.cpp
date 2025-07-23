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
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    ll even = 0, odd = 0, e = 0, o = 0;
    for(auto &i : a) {
        cin >> i;
        if(i & 1) {
            odd += i;
            o++;
        }
        else {
            even += i;
            e++;
        }
    }
    while(q--) {
        ll x, num;
        cin >> x >> num;
        if(x == 0) {
            if(num & 1) {
                even += num * e;
                odd += even;
                o += e;
                e = 0;
                even = 0;
            }
            else {
                even += num * e;
            }
        }
        else {
            if(num & 1) {
                odd += num * o;
                even += odd;
                e += o;
                o = 0;
                odd = 0;
            }
            else {
                odd += num * o;
            }
        }

        cout << odd + even << endl;
    }
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

