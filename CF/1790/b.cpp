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
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> ans;
    ans.push_back(a - b);
    ll divi = b / (n - 1);
    ll suma = 0;
    for(int i = 1; i < n - 1; i++) {
        ans.push_back(divi);
        suma += divi;
    }

    for(int i = 1; i < ans.size(); i++) {
        ll bruh = suma;
        suma -= ans[i];
        ans[i] += min(bruh - (b - 1), b - ans[i]);
        suma += ans[i];
    }

    ans.push_back(b - suma);
    for(auto i : ans) {
        cout << i << ' ';
    }
    cout << endl;
    
}







signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

