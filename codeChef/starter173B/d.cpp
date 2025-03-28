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

void solve(){        
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll mini = (1 << 30);
    ll ini = 0;
    for(int i = 0; i < m; i++) {
        cin >> b[i];
        if(b[i] < mini) {
            ini = i;
            mini = b[i];
        }
    }
    auto it = b.begin() + ini;
    vector<ll> smallest;
    for(int i = 0; i < m; i++) {
        if(it == b.end()) {
            it = b.begin();
        }
        smallest.push_back(*it);
        it++;


    }
    bool flag = false;
    for(int i = 0; i < n - m; i++) {
        if(flag && m > 1) {
            a[i] = mini;
            continue;
        }
        if(a[i] > mini) {
            a[i] = mini;
            flag = true;
        }
    }
    vector<ll> subArr;
    for(int i = n - m; i < n; i++) {
        subArr.push_back(a[i]);
    }
    for(int i = 0; i < n - m; i++) {
        cout << a[i] << ' ';
    }
    if(subArr > smallest || flag && m > 1) {
        for(int i = 0; i < m; i++) {
            cout << smallest[i] << ' ';
        }
        cout << endl;
    }
    else {
        for(int i = 0; i < m; i++) {
            cout << subArr[i] << ' ';
        }
        cout << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

