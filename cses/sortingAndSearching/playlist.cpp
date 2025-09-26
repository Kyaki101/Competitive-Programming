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

void solve(){        
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    queue<ll> songs;
    set<ll> nums;
    ll maxi = 0;
    for(int i = 0; i < n; i++) {
        if(nums.find(a[i]) != nums.end()) {
            while(songs.front() != a[i]) {
                nums.erase(songs.front());
                songs.pop();
            }
            songs.pop();
            nums.erase(a[i]);
        }
        nums.insert(a[i]);
        songs.push(a[i]);
        maxi = max((ll)nums.size(), maxi);
    }
    cout << maxi << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

