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

void upArr(vector<ll> & diffArr, ll l, ll r) {
    if(r == diffArr.size() - 1) {
        diffArr[l] ++;
        return;
    }
    diffArr[l] ++;
    diffArr[r + 1] --;
}

void solve(){        
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    sort(ALL(a));
    vector<ll> good;
    ll curr = -1;
    for(int i = 0; i < n; i++) {
        if(a[i] == curr + 1) {
            curr ++;
            good.push_back(0);
            good[a[i]] ++;
        }
        else if(a[i] == curr) {
            good[a[i]] ++;
        }
    }
    vector<ll> diffArr(n + 1, 0);
    if(good.size() == 0) {
        for(int i = 0; i <= n; i++) {
            cout << 1 << ' ';
        }
        cout << endl;
        return;
    }
    upArr(diffArr, good[0], n);
    ll tot = n;
    ll padding = 0;
    for(int i = 0; i < good.size(); i++) {
        tot -= good[i];
        ll nxt = i + 1;
        if(nxt == good.size()) {
            upArr(diffArr, 0, padding + tot + good[i] - 1);
            continue;
        }
        upArr(diffArr, good[nxt], good[nxt] + (good[i] - 1) + padding + (tot - good[nxt]));

        padding += (good[i] - 1);

    }

    ll cnt = 0;
    for(auto i : diffArr) {
        cnt += i;
        cout << cnt << ' ';
    }
    cout << endl;
     


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

