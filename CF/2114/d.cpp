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


bool cmp(pair<ll, ll> & a, pair<ll, ll> & b) {
    return a.second < b.second;
}
bool cmp2(pair<ll, ll> & a, pair<ll, ll> & b) {
    return a.second > b.second;
}

bool cmp3(pair<ll, ll> & a, pair<ll, ll> & b) {
    return a.first > b.first;
}

void solve(){        
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    if(n == 1) {
        cout << 1 << endl;
        return;
    }
    if(n == 2) {
        cout << 2 << endl;
        return;
    }
    vector<pair<ll, ll>> lowCol(ALL(a));
    vector<pair<ll, ll>> hCol(ALL(a));
    vector<pair<ll, ll>> lowRow(ALL(a));
    vector<pair<ll, ll>> hRow(ALL(a));
    sort(ALL(lowCol), cmp);
    sort(ALL(hCol), cmp2);
    sort(ALL(lowRow));
    sort(ALL(hRow), cmp3);

    ll lowest = (1LL << 62);
    for(int i = 0; i < n; i++) {
        ll q, w, e, r;
        if(lowCol[0] == a[i]) {
            q = 1;
        }
        else q = 0;

        if(hCol[0] == a[i]) {
            w = 1;
        }
        else w = 0;

        if(lowRow[0] == a[i]) {
            e = 1;
        }
        else e = 0;

        if(hRow[0] == a[i]) {
            r = 1;
        }
        else r = 0;

        ll width = abs(lowCol[q].second - hCol[w].second) + 1;
        ll height = abs(lowRow[e].first - hRow[r].first) + 1;
        ll area = width * height;
//        DEBUG(area);
//        cout << a[i].first << ' ' << a[i].second << endl;
 //       cout << lowCol[q].second << ' ' << hCol[w].second << ' ' << lowRow[e].first << ' ' << hRow[r].first << endl;
        if(area == a.size() - 1) {
            if(width < height) {
                lowest = min(lowest, width * (height + 1));
            }
            else {
                lowest = min(lowest, (width + 1) * height);
            }
        }
        else {
            lowest = min(lowest, width * height);
        }
    }
    cout << lowest << endl;


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

