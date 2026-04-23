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
	map<ll, ll> nums;
	for(auto i : a) nums[i]++;
	if(nums.size() == 1) {
		cout << "YES" << endl;
		return;
	}
	ll it = 0;
	bool win = true;
	for(auto [x, y] : nums) {
		if(it == nums.size() - 1) {
			continue;
		}
		if(it == 0 && y % 2 == 0) {
			win = false;
			continue;
		}
		if(y % 2 == 1 && it != 0) {

			win = false;
		}
		it++;
	}
	if(win) {
		cout << "YES" << endl;
		return;
	}
	cout << "NO" << endl;
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
