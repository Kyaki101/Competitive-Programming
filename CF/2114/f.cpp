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

vector<bool> criba(100000, true;);

void solve(){        
    ll x, y, k;
    cin >> x >> y >> k;

    multimap<ll> p1, p2;
    for(int i = 2; i < 100000; i++) {
        while(!criba[i] && x % i == 0) {
            x /= i;
            p1.insert(i);
        }
    }
    for(int i = 2; i < 100000; i++) {
        while(!criba[i] && y % i == 0) {
            y /= i;
            p2.insert(i);
        }
    }
    for (int i : p2) {
        auto it = p1.find(i);
        if (it != p1.end()) {
            p1.erase(it); // only erases one instance of x
        }
    }
    ll count = 0;
    for(auto i : p1) {
        if(k < i) {
            cout << -1 << endl;
        }
        count ++;
    }
    cout << count << endl;

}

signed main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    criba[0] = true;
    criba[1] = true;
    for(int i = 2; i < 100000; i++) {
        if(!criba[i]) for(int j = 2 * i; j < 100000; j += i) {
            criba[j] = true;
        }
    }
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

