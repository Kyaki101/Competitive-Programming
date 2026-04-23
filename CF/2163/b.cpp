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
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll index = 0;
    ll mini = 0, maxi = 0;
    for(auto &i : a){
        cin >> i;
        if(a[index] < a[mini]) mini = index;
        if(a[index] > a[maxi]) maxi = index;
        index ++;
    }
    string s;
    cin >> s;
    if(s[mini] == '1' || s[maxi] == '1' || s[0] == '1' || s[n - 1] == '1') {
        cout << -1 << endl;
        return;
    }
    cout << 5 << endl;
    cout << 1 << ' ' << mini + 1 << endl;
    cout << 1 << ' ' << maxi + 1 << endl;
    cout << mini + 1 << ' ' << n << endl;
    cout << maxi + 1 << ' ' << n << endl;
    cout << min(maxi, mini) + 1 << ' ' << max(maxi, mini) + 1 << endl;
    
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

