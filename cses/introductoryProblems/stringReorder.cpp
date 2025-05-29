#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define pb push_back
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")

char nxtChar(vector<ll> & vals, ll i, ll n, vector<char> & ans) {
    ll it = 0LL;
    while(it < 26) {
        if(vals[it] == 0) {
            it++;
            continue;
        } 
        auto nxt = it + 1;
        bool flag = true;
        while(nxt < 26 && flag) {
            if((n - (i + 1) + 1) / 2 < vals[nxt]) {
                flag = false;
            }
            nxt++;
        }
        
        if(vals[it] > 0 && flag && (i == 0 || ans[i - 1] != (char) (it + 'A'))) {
            vals[it] --;
            return (char)(it + 'A');
        }
        it++;
    }
    return 0;
}

void solve(){        
    string s;
    cin >> s;
    ll n = s.size();
    vector<char> ans(n);
    vector<ll> vals(26, 0LL);
    for(int i = 0; i < n; i++) {
        vals[s[i] - 'A'] ++;
    }
    for(auto i : vals) {
        if(i > (n + 1) / 2) {
            cout << -1 << endl;
            return;
        }
    }
    for(int i = 0; i < n; i++) {
        ans[i] = nxtChar(vals, i, n, ans);
    }
    for(auto i : ans) {
        cout << i;
    }
    cout << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

