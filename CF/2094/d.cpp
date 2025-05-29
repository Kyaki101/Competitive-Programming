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
ll n;

void solve(){        
    string s;
    string p;
    cin >> s >> p;
    ll acum = 0;
    ll i = 0; 
    ll j = 0;
    char prev = 'c';
    while(i < s.size() && j < p.size()) {
        if(s[i] != p[j]) {
            if(acum == 0 || p[j] != prev) {
                cout << "NO" << endl;
                return;
            }
            acum --;
            j++;
        }
        else {
            if(s[i] == prev) {
                acum ++;
            }
            else {
                prev = s[i];
                acum = 1;
            }
            i++;
            j++;
        }
    }
    while(acum > 0 && j < p.size()) {
        if(p[j] != prev) {
            cout << "NO" << endl;
            return;
        }

        j ++;
        acum --;
    }
    if(i < s.size()) {
        cout << "NO" << endl;
        return;
    }

    if(j < p.size()) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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

