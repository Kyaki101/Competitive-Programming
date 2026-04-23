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
    vll a(n);
    ll maxi = 0;
    vll evens;
    ll odds = 0;
    for(auto &i : a) {
        cin >> i;
        if(i & 1) {
            maxi = max(i, maxi);
            odds ++;
        }
        if(!(i & 1)) evens.PB(i);
    }
    odds --;

    sort(evens.rbegin(), evens.rend());

    if(maxi == 0) {
        for(int i = 0; i < n; i++) {
            cout << 0 << ' ';
        }
        cout << endl;
        return;
    }
    vll ans;
    ans.PB(maxi);
    ll j = 0;
    ll suma = 0;
    ll curr = 1;
    bool done = false;
    bool turn = false;
    ll s = evens.size();
    for(int i = 1; i < n; i++) {
        if(s == 0) {
            if(curr & 1) {
                ans.PB(0);
            }
            else {
                ans.PB(maxi);
            }
            odds --;
            curr ++;
            continue;
        }

        if(j == s) {
            if(odds == 1) {
                if(curr & 1) {
                    ans.PB(0);
                }
                else {
                    ans.PB(maxi + suma);
                }
                odds --;
                curr ++;
                continue;
            }
            else {
                j --;
                suma -= evens[j];
                odds -= 2;
                ans.PB(suma + maxi);
            }

        }
        else {
            suma += evens[j];
            ans.PB(suma + maxi);
            j++;
        }
    }
    for(auto i : ans) {
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

