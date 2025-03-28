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
    ll n;
    cin >> n;
    ll sqr = sqrt(n);
    ll suma = (n * (n + 1)) / 2;
 
    ll suSq = sqrt(suma);
    if(suSq * suSq == suma) {
        cout << -1 << endl;
        return;
    }

    set<ll> available;
    vector<ll> ans;
    suma = 0;
    for(int i = 1; i <= n; i++) {
        available.insert(i);
    }

    for(int i = 0; i < n; i++) {
        bool found = false;

        for(auto it = available.rbegin(); !found && it != available.rend(); it++) {
            ll cand = *it;
            ll candS = cand + suma;
            ll s = sqrt(candS);
            if(s * s != candS) {
                ans.push_back(cand);
                available.erase(cand);
                found = true;
                suma += cand;
            }

        }
        if(!found) {
            cout << -1 << endl;
        }

    }

    for(auto i : ans) cout << i << ' ';
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
