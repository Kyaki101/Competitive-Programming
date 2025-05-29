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

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    if(a.first != b.first) {
        return a.first < b.first;
    }
    return a.second> b.second;
}

void solve(){        
    ll n;
    cin >> n;
    vector<pair<ll, ll>> ranges(n);
    map<pair<ll, ll>, ll> mapa;
    for(int i = 0; i < n; i++) {
        cin >> ranges[i].first >> ranges[i].second;
        mapa[ranges[i]] = i;
    }
    sort(ALL(ranges), cmp);
    vector<ll> under(n, 0);
    ll maxi = 0;
    for(int i = 0; i < n; i++) {
        if(maxi >= ranges[i].second) {
            under[mapa[ranges[i]]] = 1;
        }
        else {
            maxi = ranges[i].second;
        }
    }
    ll mini = (1LL << 60);
    vector<ll> over(n, 0);
    for(int i = n - 1; i > -1; i--) {
        if(mini <= ranges[i].second) {
            over[mapa[ranges[i]]] = 1;
        }
        else {
            mini = ranges[i].second;
        }

    }
    for(auto i : over) {
        cout << i << ' ';
    }
    cout << endl;
    for(auto i : under) {
        cout << i << ' ';
    }   
    cout << endl;

    

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

