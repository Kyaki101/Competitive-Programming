#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
typedef long long int ll;
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

void solve(){        
    ll n;
    cin >> n;
    set<ll> nums;
    for(int i = 1; i <= n; i++) {
        nums.insert(i);
    }
    bool del = false;
    auto it = nums.begin();

    while(!nums.empty()) {
        if(it == nums.end()) {
            it = nums.begin();
            continue;
        }
        if(del) {
            cout << *it << ' ';
            it = nums.erase(it);
            del = false;
        }
        else {
            it++;
            del = true;
        }
    }
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}

