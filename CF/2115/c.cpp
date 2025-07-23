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
    cin >> n;
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    set<ll> nums(ALL(a));
    ll gc = a[0];
    for(int i = 1; i < n; i++) {
        gc = gcd(a[i], gc);
    }
    if(nums.find(gc) != nums.end()) {
        ll c = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] != gc) {
                c++;
            }
        }
        cout << c << endl;
        return;
    }
    ll mini = (1 << 30);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j && gcd(a[i], a[j]) == gc) {
                cout << n << endl;
                return;
            }
            if(i != j) mini = min(gcd(a[i], a[j]), mini);
        }
    }


    ll steps = 0;
    while(mini != gc) {
        for(int i = 0; i < n; i++) {
            mini = min(gcd(a[i], mini), mini);
        }
        steps ++;
    }
    cout << n + steps << endl;


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

