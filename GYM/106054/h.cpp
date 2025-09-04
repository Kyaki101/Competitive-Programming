#include <bits/stdc++.h>
using namespace std;

#define SET(m,i) ((m)|(1ULL<<(i)))
#define TEST(m,i) ((m)&(1ULL<<(i)))
#define CLEAR(m,i) ((m)&~(1ULL<<(i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define DEBUG_ALL(a) for(auto &w:a)cout<<w<<' ';cout<<endl;
#define ALLN(x,n) begin(x), begin(x)+n
#define ALL(x) begin(x), end(x)
#define vec vector
#define snd second
#define fst first
#define pb push_back
#define ll long long
const ll MAX = 2e5+20, MOD = 1e9+7;

void solve(){        
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    sort(ALL(a));
    if(a.size() == 1 && a[0] != 1) {
        cout << a[0] << ' ' << 1 << endl;
        return;
    }
    if(a.size() == 1 && a[0] == 1) {
        cout << '*' << endl;
        return;
    }
    if(a[0] != 1) {
        cout << a[n - 1] << ' ' << 1 << endl;
        return;
    }
    for(int i = 0; i < n - 1; i++) {
        if(a[n - 1] % a[i] != 0) {
            cout << '*' << endl;
            return;
        }
    }
    ll l = 0;
    ll r = n - 1;
    bool fd = false;
    set<ll> nums(ALL(a));
    ll fdCount = 0;
    ll br = 0;
    for(auto i : nums) {
        if(nums.find(a[n - 1] / i) == nums.end()) {
            br = i;
            fdCount ++;

        }

    }

    ll bruh = sqrt(a[n - 1]);
    DEBUG(bruh);
    if(br == 0 && bruh * bruh != a[n - 1]) {
        cout << '*' << endl;
        return;
    }
    if(br == 0 && bruh * bruh == a[n - 1] && nums.find(bruh) != nums.end()) {
        cout << a[n - 1] << ' ' << bruh << endl;
        return;
    }
    if(br) {
        cout << a[n - 1] << ' ' << a[n - 1] / br << endl;
        return;
    }
    

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    while(T--){
        solve();
        //cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}

