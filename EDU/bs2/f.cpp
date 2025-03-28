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


bool valid(string & s, ll index, vector<ll> & a, string & goal) {
    unordered_set<ll> is;
    for(int i = 0; i <= index; i++) {
        is.insert(a[i] - 1);
    }

    ll j = 0;

    for(int i = 0; i < s.size() && j < goal.size(); i++) {
        if(s[i] == goal[j] && is.find(i) == is.end()) j++;
    }
    if(j == goal.size()) return true;
    return false;

}

void solve(){        
    string s;
    cin >> s;
    string t;
    cin >> t;
    ll n = s.size();
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll r = n;
    ll l = -1;
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(valid(s, mid, a, t)) {
            l = mid;
        }
        else r = mid;
    }
    cout << l + 1 << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}

