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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto &i : a) {
        cin >> i;
    }
    vector<pair<ll, ll>> hoops(n, {0, 0});
    for(int i = 0; i < n; i++) {
        cin >> hoops[i].first >> hoops[i].second;
    }
    multiset<ll> tops;
    for(auto i : hoops) {
        tops.insert(i.second);
    }

    stack<ll> cola;
    ll curr = 0;
    for(int i = 0; i < n; i++) {
        ll bruh = *(tops.begin());
        if(a[i] == 1) {
            if(curr == bruh && !cola.empty()) {
                a[cola.top()] = 0;
                cola.pop();
            }
            else {
                curr ++;
            }
        }
        else if(a[i] == -1) {
            if(curr < bruh) {
                a[i] = 1;
                cola.push(i);
                curr ++;
            }
            else {
                a[i] = 0;
            }
        }
        tops.erase(tops.find(hoops[i].second));
    }
    curr = 0;
    for(int i = 0; i < n; i++) {
        curr += a[i];
        if(curr > hoops[i].second || curr < hoops[i].first) {
            cout << -1 << endl;
            return;
        }
    }
    for(auto i : a) {
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

