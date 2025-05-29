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
    if(n == 2) {
        cout << "! " << 1 << ' ' << 0 << endl;
        return;
    }
    ll best = 0;
    for(int i = 1; i < n; i++) {
        cout << "? " << best << ' ' << best << ' ' << i << ' ' << i << endl;
        char res;
        cin >> res;
        if(res == '<') best = i;
    }
    ll sec = 0;
    vector<ll> cands;
    cands.push_back(0);
    for(int i = 1; i < n; i++) {
        cout << '?' << ' ' << best << ' ' << sec << ' ' << best << ' ' << i << endl;
        char res;
        cin >> res;
        if(res == '<') {
            sec = i;
            cands.clear();
            cands.push_back(i);
        }
        if(res == '=') cands.push_back(i);
    }
    ll sb = cands[0];
    for(int i = 1; i < cands.size(); i++) {
        cout << "? " << sb << ' ' << sb << ' ' << cands[i] << ' ' << cands[i] << endl;
        char res;
        cin >> res;
        if(res == '>') sb = cands[i];
    }
    cout << '!' << ' ' << best << ' ' << sb << endl;


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

