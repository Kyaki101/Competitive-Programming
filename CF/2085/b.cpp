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
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll sub = 0;
    vector<ll> novo;
    vector<pair<ll, ll> > moves;
    for(int i = 0; i < n - 1; i++, i++) {
        if(a[i + 1] == 0 || a[i] == 0) {
            moves.push_back({(i + 1) - sub, (i + 2) - sub});
            novo.push_back(1);
            sub ++;
        }
        else {
            novo.push_back(a[i]);
            novo.push_back(a[i + 1]);
        }
    }
    if(n & 1) {
        novo.push_back(a[n - 1]);
    }

    if(novo[novo.size() - 1] == 0) {
        moves.push_back({novo.size() - 1, novo.size()});
        novo.pop_back();
    }
    moves.push_back({1, novo.size()});


    cout << moves.size() << endl;

    for(auto i : moves) {
        cout << i.first << ' ' << i.second << endl;
    } 
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

