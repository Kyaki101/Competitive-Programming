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

void solve(){        
    
    ll n;
    cin >> n;
    string s;
    cin >> s;
    if(n == 1) {
        cout << 1 << endl;
        return;
    }
    vector<vector<ll>> mat(26, vector<ll>(26, 0));
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            char e = 'a' + i;
            char o = 'a' + j;
            if(n & 1) {
                vector<ll> pref(n, 0);
                vector<ll> suff(n, 0);
                ll counter = 0;
                for(int k = 0; k < n; k++) {
                    if(k & 1) {
                        if(s[k] != o) counter ++;
                    }
                    else {
                        if(s[k] != e) counter ++;
                    }
                    pref[k] = counter;
                }
                suff[n - 1] = 0;
                for(int k = n - 2; k > -1; k--) {
                    suff[k] = suff[k + 1];
                    if(k & 1) {
                        if(s[k + 1] != o) {
                            suff[k] ++;
                        }
                    }
                    else {
                        if(s[k + 1] != e) suff[k] ++;
                    }

                }

                ll mini = (1 << 30);
                for(int k = 0; k < n; k++) {
                    ll val;
                    if(k == 0) val = suff[k];
                    if(k == n - 1) val = pref[k - 1];
                    else if(k != 0 && k != n - 1) val = suff[k] + pref[k - 1];

                    mini = min(val, mini);
                }
                mat[i][j] = mini + 1;
            }
            else {
                ll counter = 0;
                for(int k = 0; k < n; k++) {
                    if(k & 1) {
                        if(s[k] != o) counter ++;
                    }
                    else {
                        if(s[k] != e) counter ++;
                    }

                }
                mat[i][j] = counter;

            }
        }

    }
    ll mini = (1 << 30);
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            mini = min(mini, mat[i][j]);

        }
    }
    cout << mini << endl;
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

