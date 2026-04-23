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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll bruh = 0;
    for(auto &i : a) {
        cin >> i;
        if(i == k) bruh ++;
    }
    set<ll> nums;
    ll backups = 0;
    for(auto i : a) {
        if(i < k) {
            if(nums.find(i) != nums.end()) {
                backups++;
            }
            else {
                nums.insert(i);
            }
        }
        else {
            backups++;
        }
    }
    ll curr = 0;
    ll used = 0;
    ll cnt = 0;
    for(auto i : nums) {
        if(i == curr) {
            curr++;
        }
        else {
            cnt += i - curr;
            used += i - curr;
            curr = i + 1;
        }
    }
    if(curr < k) {
        cnt += k - curr;
        used += k - curr;
    }
    if(used < bruh) {
        cout << cnt + bruh - used << endl;
        return;
    }
    cout << cnt << endl;
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

