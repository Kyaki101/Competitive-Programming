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
    vector<double> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    double ans = 0;
    vector<double> rejects;
    map<char, ll> mapa;

    for(int i = 0; i < n; i++) {
        string s = to_string(a[i]);
        ll b = s.size() - 5;
        if(s[s.size() - 5] < '3') {
            s[s.size() - 5] = '0';
            ans += stod(s);
        }
        else if(s[b] >= '5' && s[b] < '8') {
            s[b] = '5';
            ans += stod(s);
        }
        else {
            mapa[s[b]] ++;
            ans += a[i];
        }
    }


    ll pre;

    ans -= min(mapa['3'], mapa['4']) * 0.02;
    pre = mapa['3'];
    mapa['3'] -= min(mapa['3'], mapa['4']);
    mapa['4'] -= min(pre, mapa['4']);


    ans -= min(mapa['3'], mapa['9']) * 0.02;
    pre = mapa['9'];
    mapa['9'] -= min(mapa['3'], mapa['9']);
    mapa['3'] -= min(mapa['3'], pre);


    ans -= min(mapa['4'], mapa['8']) * 0.02;
    pre = mapa['4'];
    mapa['4'] -= min(mapa['4'], mapa['8']);
    mapa['8'] -= min(mapa['8'], pre);


    ans -= min(mapa['8'], mapa['9']) * 0.02;
    pre = mapa['8'];
    mapa['8'] -= min(mapa['8'], mapa['9']);
    mapa['9'] -= min(pre, mapa['9']);

    ll suma = 0;
    suma += mapa['3'] + mapa['4'] + mapa['8'] + mapa['9'];
    suma /= 2;
    ans -= suma * 0.01;

    cout << fixed << setprecision(2) << ans << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}

