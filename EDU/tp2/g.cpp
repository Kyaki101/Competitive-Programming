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

stack<ll> s1, s2, s1g, s2g;

void add(ll x) {
    s2.push(x);
    if(s2g.empty()) {
        s2g.push(x);
    }
    else {
        s2g.push(gcd(s2g.top(), x));
    }
}
void remove() {
    if(s1.empty()) {
        while(!s2.empty()) {
            ll x = s2.top();
            s2.pop();
            s2g.pop();
            s1.push(x);
            if(s1g.empty()) s1g.push(x);
            else s1g.push(gcd(s1g.top(), x));
        }
    }
    s1.pop();
    s1g.pop();

}

bool good() {
    if(s1.empty()) {
        return s2g.top() == 1;
    }
    if(s2.empty()) {
        return s1g.top() == 1;
    }
    return gcd(s1g.top(), s2g.top()) == 1;

}

void solve(){        
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto &i : a) {
        cin >> i;
        if(i == 1) {
            cout << 1 << endl;
            return;
        }
    }
    ll l = 0, mini = (1 << 30);
    for(int r = 0; r < n; r++) {
        add(a[r]);
        bool flag = good();
        while(good()) {
            remove();
            l++;
        }
        if(flag) {
            mini = min(mini, r - l + 2);
        }

    }
    if(mini == (1 << 30)) {
        cout << -1 << endl;
        return;
    }
    cout << mini << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

