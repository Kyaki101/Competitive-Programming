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

vector<vll> sieve(200002);

void solve(){        
    ll n;
    cin >> n;
    vll a(n), b(n);
    ll cnt = 0;
    for(auto &i : a) {
        cin >> i;
        if(!(i & 1)) cnt ++;
    }
    for(auto &i : b) cin >> i;
    if(cnt >= 2) {
        cout << 0 << endl;
        return;
    }
    set<ll> nums;
    for(auto i : a) {
        for(auto j : sieve[i]) {
            if(nums.find(j) != nums.end()) {
                cout << 0 << endl;
                return;
            }
            nums.insert(j);
        }
    }
    for(auto i : a) {
        for(auto j : sieve[i + 1]) {
            if(nums.find(j) != nums.end()) {
                cout << 1 << endl;
                return;
            }
        }
    }
    cout << 2 << endl;
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    for(int i = 2; i < 200002; i++) {
        for(int j = i; j < 200002; j+= i) {
            sieve[j].PB(i);
        }
    }
    while(t--){
        solve();
    }return 0;
}

