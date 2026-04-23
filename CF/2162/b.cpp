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
    string s;
    cin >> s;
    vector<ll> ind;
    bool one = false;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') ind.PB(i + 1);
        if(s[i] == '1') one = true;
    }
    if(!one) {
        cout << ind.size() - 1 << endl;
        for(int i = 0; i < ind.size() - 1; i++) {
            cout << ind[i] << ' ';
        }
        cout << endl;
        return;
    }
    cout << ind.size() << endl;
    for(auto i : ind) cout << i << ' ';
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

