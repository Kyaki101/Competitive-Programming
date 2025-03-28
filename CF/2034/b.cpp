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
    ll n, m, k;
    cin >> n >> m >> k;
    string s;;
    cin >> s;
    ll iniSum = 0;
    if(m > n) {
        cout << 0 << endl;
        return;
    }
    vector<ll> acum(n, 0);
    acum[0] = s[0] - '0';
    for(int i = 1; i < n; i++) {
        acum[i] = acum[i - 1] + (s[i] - '0');
    }
    ll index = 0;
    for(int i = 0; i < m - 1; i++) {
        iniSum += s[i] - '0';
        index ++;
    }
    ll ans = 0;
    for(int i = index; i < n; i++) {
        iniSum += s[i] - '0';


        if(iniSum == 0) {
            ll bruh = i;
            while(i < n && i < bruh + k) {
                iniSum ++;
                i++;
            }
            i--;
            ans ++;

            iniSum = (acum[min(n, i + (m - 1))] - acum[(i == 0) ? 0 : i - 1]) + (s[i] != '1'); 
            s[i] = '1';
            i += m - 1;

        }

        iniSum -= s[max(0LL, i - (m - 1))] - '0';
    }
    cout << ans << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

