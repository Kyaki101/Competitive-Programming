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
vector<vector<ll>> ans;

void combinations(vector<ll> & nums, ll i, vector<ll> curr, ll cap = 0) {

    if(i == nums.size()) {
        if(cap & 1) {
            ans.push_back(curr);
        }
        else {
            ans.push_back(curr);
        }
        return;
    }
    vector<ll> bruh = curr;
    bruh.push_back(nums[i]);
    combinations(nums, i + 1, bruh, cap + 1);
    combinations(nums, i + 1, curr, cap);


}

void solve(){        
    ll l, r;
    cin >> l >> r;
    ans.clear();
    vector<ll> nums{2, 3, 5, 7};
    vector<ll> bruh;
    ll res = 0;
    combinations(nums, 0, bruh);
    for (auto &i : ans) {
        ll num = 1;
        if(i.size() != 0) {
            for(auto j : i) {
                num *= j;
            }
            ll pre = r / num - (l - 1) / num;
            if(i.size() & 1) {
                res += pre;
            }
            else res -= pre;
        }

    }
    cout << (r - l) + 1 - res << endl;


}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
        //cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}

