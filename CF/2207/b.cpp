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
    ll n, m, t;
    cin >> n >> m >> t;
    vll a(n);
    for(auto &i : a) cin >> i;
    multiset<ll> nums;
    for(int i = 0; i < m; i++) nums.insert(0);
    ll index = 0;
    for(int i = 1; i <= t; i++) {
        if(n - index < m) {
            while((ll)nums.size() != n - index + 1) {
                nums.erase(nums.begin());
            } 
        }
        ll mini = *nums.begin();
        mini ++;
        nums.erase(nums.begin());
        nums.insert(mini);
        ll maxi = *(--nums.end());
        if(index < n && i == a[index]) {
            nums.erase(nums.find(maxi));
            index ++;
            nums.insert(0);
        }

    }
    cout << *(--nums.end()) << endl;


    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        #ifdef ICPC 
            cout << "--------------------------------------------------" << endl;
        #endif // 
    }
    #ifdef ICPC 
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}

