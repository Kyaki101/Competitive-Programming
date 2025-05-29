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

void solve(){        
    ll n, k;
    cin >> n >> k;
    vector<ll> a(2 * n);
    for(auto &i : a) {
        cin >> i;
    }
    vector<ll> left;
    vector<ll> right;
    ll len = 2 * k;
    set<ll> f;
    set<ll> s;
    ll lside = 0;
    ll rside = 0;
    for(int i = 0; i < n && lside < len; i++) {
        if(f.find(a[i]) != f.end()) {
            lside += 2;
            f.erase(a[i]);
            left.push_back(a[i]);
            left.push_back(a[i]);
        }
        else f.insert(a[i]);
    }

    for(int i = n; i < 2 * n && rside < len; i++) {
        if(s.find(a[i]) != s.end()) {
            rside += 2;
            s.erase(a[i]);
            right.push_back(a[i]);
            right.push_back(a[i]);
        }
        else {
            s.insert(a[i]);
        }
    }
    auto it = f.begin();
    while(lside < len) {
        left.push_back(*it);
        right.push_back(*it);
        it++;
        lside ++;
    }
    for(auto i : left) {
        cout << i << ' ';
    }
    cout << endl;
    for(auto i : right) {
        cout << i << ' ';
    }
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

