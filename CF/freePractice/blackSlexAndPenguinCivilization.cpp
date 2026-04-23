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
    ll number = (1LL << n);
    ll origi = number;
    set <ll> nums;
    while(n) {
        ll base = number - 1;
        ll i = 0;
        ll temp = (i << n) | base;
        while(temp < origi) {
            if(nums.find(temp) == nums.end()) {
                cout << temp << ' ';
                nums.insert(temp);
            }
            i++;
            temp = (i << n) | base;
        }

        n --;
        number = (1LL << n);
    }
    for(int i = 0; i < origi; i++) {
        if(nums.find(i) == nums.end()) {
            cout << i << ' ';
        }

    }

    cout << endl;

    
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

