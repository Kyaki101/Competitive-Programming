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
    vector<ll> a(n);
    vector<ll> b(n);
    map<ll, ll> mapa;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    ll counter = 0;
    ll index;
    for(int i = 0; i < n; i++) {
        if(a[i] == b[i]) {
            counter ++;
            index = i;
        }
        mapa[a[i]] = b[i];
    }
    if(counter > 1 || counter > 0 && n % 2 == 0 || counter == 0 && (n & 1)) {
        cout << -1 << endl;
        return;
    }

    for(int i = 0; i < n; i++) {
        if(mapa[mapa[a[i]]] != a[i]) {
            cout << -1 << endl;
            return;
        }
    }

    map<ll, ll> pos;
    for(int i = 0; i < n; i++) {
        pos[b[i]] = i;
    }

    vector<pair<ll, ll> > moves;

    if((n & 1) && index != n / 2) {
        swap(b[index], b[n / 2]); 
        swap(a[index], a[n / 2]);
        pos[b[index]] = index;
        moves.push_back({index + 1, n / 2 + 1});
    }


    for(int i = 0; i < n / 2; i++) {
        ll expected = n - (i + 1);
        ll cur = pos[a[i]];
        if(pos[a[i]] != expected) {
            ll num = b[expected];
            swap(a[expected], a[cur]);
            swap(b[expected], b[cur]);
            pos[num] = cur;
            moves.push_back({cur + 1, n - (i + 1) + 1});
        }
    }


    cout << moves.size() << endl;
    for(auto i : moves) {
        cout << i.first << ' ' << i.second << endl;
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

