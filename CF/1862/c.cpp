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


void update(vector<ll> & diff, ll l, ll r) {

    diff[l] ++;
    if(r == diff.size() - 1) {
        return;
    }
    diff[r + 1]--;
}

void solve(){        
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> mapa;
    for(auto &i : a) {
        cin >> i;
        mapa[i] ++;
    }
    if(a[0] > 200001) {
        cout << "NO" << endl;
        return;
    }
    vector<ll> diff(n, 0);
    for(int i = 0; i < n; i++) {
        if(a[i] > n) {
            cout << "NO" << endl;
            return;
        }
        update(diff, 0, a[i] - 1);

    }
    vector<ll> ans;
    ll curr = 0;
    for(int i = 0; i < n; i++) {
        curr += diff[i];
        ans.push_back(curr);
    }
    if(ans == a) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
    return;

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

