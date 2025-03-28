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
    string s;
    cin >> s;
    ll suma = 0;
    suma = accumulate(ALL(s), 0) - '0' * s.size();
    if(suma % 9 == 0) {
        cout << "YES" << endl;
        return;
    }
    ll num = suma % 9;
    map<ll, ll> mapa;
    mapa[1] = 4;
    mapa[2] = 8;
    mapa[3] = 3;
    mapa[4] = 7;
    mapa[5] = 2;
    mapa[6] = 6;
    mapa[7] = 1;
    mapa[8] = 5;
    ll threes = 0;
    ll twos = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '3') threes ++;
        else if(s[i] == '2') twos ++;
    }
    ll steps = mapa[num];
    if(steps == 6 && threes >= 2) {
        cout << "YES" << endl;
        return;
    }
    if(steps == 3 && threes >= 1) {
        cout << "YES" << endl;
        return;
    }


    if(steps >= 3 && threes > 0) {
        steps -= 3;
        threes --;
    }
    if(steps >= 3 && threes > 0) {
        steps -= 3;
    }


    while(twos >= 1) {

        steps --;
        twos --;
        if(steps == 0) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

