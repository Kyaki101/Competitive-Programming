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

stack<ll> s1, s2, s1Max, s1Min, s2Max, s2Min;

void add(ll x) {
    s2.push(x);
    if(s2Max.empty()) {
        s2Max.push(x);
    }
    else {
        s2Max.push(max(x, s2Max.top()));
    }
    if(s2Min.empty()) {
        s2Min.push(x);
    }
    else {
        s2Min.push(min(x, s2Min.top()));
    }

}

void transfer() {
    ll x = s2.top();
    s1.push(x);
    s2.pop();
    s2Max.pop();
    s2Min.pop();
    if(s1Max.empty()) {
        s1Max.push(x);
    }
    else {
        s1Max.push(max(s1Max.top(), x));
    }
    if(s1Min.empty()) {
        s1Min.push(x);
    }
    else {
        s1Min.push(min(s1Min.top(), x));
    }

}

void remove() {
    if(s1.empty()) {
        while(!s2.empty()) {
            transfer();
        }
    }
    if(s1.size() != 0) {
        s1.pop();
        s1Max.pop();
        s1Min.pop();
    }

}

bool good(ll k) {
    if(s1.empty()) {
        return (s2Max.top() - s2Min.top() <= k);
    }
    if(s2.empty()) {
        return (s1Max.top() - s1Min.top() <= k);
    }
    return (max(s1Max.top(), s2Max.top()) - min(s1Min.top(), s2Min.top()) <= k);
}

void solve(){        
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    ll l = 0, ans = 0;
    for(int r = 0; r < n; r++) {
        add(a[r]);
        while(!good(k)) {
            remove();
            l++;
        }
        ans += r - l + 1;
    }
    cout << ans << endl;
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

