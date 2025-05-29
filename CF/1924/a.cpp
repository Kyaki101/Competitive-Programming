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

void checker(vector<vector<ll> > & pref, vector<vector<ll> > & suff, ll c, ll index, vector<vector<char>> & valid, ll k, ll n) {
    vector<ll> beh(k, 0);
    vector<ll> front(k, 0);
    for(int i = 0; i < k; i++) {
        if(index == 0 && suff[0].size() > 1) {
            front[i] = suff[i][index + 1];
        }
        else if(index == suff[0].size() - 1 && suff[0].size() > 1) {
            beh[i] = pref[i][index - 1];
        }
        else if(suff[0].size() > 1) {
            beh[i] = pref[i][index - 1];
            front[i] = suff[i][index + 1];
        }
    }
    ll b = 0;
    ll f = n - 1;
    for(int i = 0; i < n; i++) {
        char good = '0';
        for(int j = 0; j < k; j++) {
            if(beh[j] < b || front[j] < f) {
                good = 'a' + j;
            }
        }
        if(good == '0' && valid[c][i] != '0') valid[c][i] = '0';
        else if(good != '0' && valid[c][i] != '0') valid[c][i] = good;
        b ++;
        f --;
    }


}

void solve(){        
    ll n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;
    vector<vector<ll> > pref(k, vector<ll>(m, 0));

    vector<vector<ll> > suff(k, vector<ll>(m, 0));

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < k; j++) {
            if(i != 0) pref[j][i] = pref[j][i - 1];
        }
        pref[s[i] - 'a'][i] ++;
    }

    for(int i = m - 1; i > -1; i--) {
        for(int j = 0; j < k; j++) {
            if(i != m - 1) suff[j][i] = suff[j][i + 1];
        }
        suff[s[i] - 'a'][i] ++;
    }

    vector<vector<char>> valid(k, vector<char>(n, '1'));

    for(int i = 0; i < m; i++) {
        ll c = s[i] - 'a';

        checker(pref, suff, c, i, valid, k, n);
    }

    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n; j++) {
            if(valid[i][j] == '1') {
                cout << "NO" << endl;
                for(int d = 0; d < n; d++) {
                    cout << (char)('a' + i);
                }
                cout << endl;
                return;
            }
            if(valid[i][j] != '0') {
                cout << "NO" << endl;
                for(int w = 0; w < j; w++) {
                    cout << valid[i][j];
                }
                cout << (char) ('a' + i);
                for(int w = j + 1; w < n; w++) {
                    cout << valid[i][j];
                }
                cout << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;


}


void u(ll b) {
    ll n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;
    if(b == 141) {
        cout << n << ' ' << k << ' ' << m << endl;
        cout << s << endl;
    }
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

