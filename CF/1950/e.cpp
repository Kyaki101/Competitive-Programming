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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> divi;
    for(int i = 1; i <= n / 2; i++) {
        if(n % i == 0) divi.push_back(i);
    }
    divi.push_back(n);

    for(int i = 0; i < divi.size(); i++) {
        string curr = "";
        map<string, ll> st;
        for(int j = 0; j < n; j++) {
            curr.push_back(s[j]);
            if((j + 1) % divi[i] == 0) {
                st[curr] ++;
                curr.clear();
            }
        }
        if(st.size() == 1) {
            cout << divi[i] << endl;
            return;
        }
        if(st.size() == 2) {
            auto it = st.begin();
            auto nxt = it;
            nxt ++;
            if(it->second == 1 || nxt->second == 1) {
                string v = it->first;
                string b = nxt->first;
                ll cnt = 0;
                for(int j = 0; j < b.size(); j++) {
                    if(v[j] != b[j]) cnt ++;
                }
                if(cnt <= 1) {
                    cout << divi[i] << endl;
                    return;
                }
            }
        }
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

