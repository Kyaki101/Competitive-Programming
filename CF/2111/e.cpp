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
    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    map<char, set<ll>> mapa;

    for(int i = 0; i < n; i++) {
        if(s[i] == 'a') {
            mapa['a'].insert(i);
            return;
        }
    }


    for(int i = 0; i < n; i++) {
        if(s[i] == 'b') {
            mapa['b'].insert(i);
        }
        
    }

    for(int i = 0; i < n; i++) {
        if(s[i] == 'c') {
            mapa['c'].insert(i);
        }
    }

    for(int i = 0; i < q; i++) {
        cout << s << endl;
        char a, b;
        cin >> a >> b;
        if(mapa[a].size() == 0) {
            continue;
        }
        if(a > b) {
            auto it = mapa[a].begin();
            mapa[b].insert(*it);
            s[*it] = b;
            mapa[a].erase(it);
        }
        else if(a < b) {
            auto it = mapa[a].end();
            it --;
            mapa[b].insert(*it);
            s[*it] = b;
            mapa[a].erase(it);
        }

    }
    cout << s << endl;
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

