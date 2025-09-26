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

void fun(ll start, ll end, vll & ans) {
    ans[start] = end + 1;
    for(int i = start + 1; i <= end; i++) {
        ans[i] = i;
    }
}

void solve(){        
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll zeros = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') zeros ++;
        if(zeros == 1 && s[i] == '1') {
            cout << "NO" << endl;
            return;
        }
        if(zeros == 1 && i == n - 1) {
            cout << "NO" << endl;
            return;
        }
        if(s[i] == '1') zeros = 0;
    }
    vector<ll> ans(n);
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') ans[i] = i + 1;
    }
    char prev = '?';
    ll start, end;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0' && prev != '0') {
            start = i;
        }
        else if(s[i] == '1' && prev == '0') {
            end = i - 1;
            fun(start, end, ans);
        }
        else if(s[i] == '0' && i == n - 1) {
            end = i;
            fun(start, end, ans);
        }
        prev = s[i];
    }
    cout << "YES" << endl;
    for(auto i : ans) cout << i << ' ';
    cout << endl;


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

