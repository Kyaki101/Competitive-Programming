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
    string s; cin >> s;
    ll acount = 0, bcount = 0, total = 0;
    auto add = [&](char c) {
        if(c == 'a') acount ++;
        if(c == 'b') total += acount, bcount ++; 
    };

    auto remove = [&](char c) {
        if(c == 'a') total -= bcount, acount --;
        if(c == 'b') bcount --;
    };

    ll ans = 0, l = 0, maxi = 0;
    for(int r = 0; r < n; r++) {
        add(s[r]);
        while(total > k) {
            remove(s[l]);
            l++;
        }
        maxi = max(r - l + 1, maxi);
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

