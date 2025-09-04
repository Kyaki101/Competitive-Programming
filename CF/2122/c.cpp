#include <bits/stdc++.h>
using namespace std;

#define SET(m,i) ((m)|(1ULL<<(i)))
#define TEST(m,i) ((m)&(1ULL<<(i)))
#define CLEAR(m,i) ((m)&~(1ULL<<(i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define DEBUG_ALL(a) for(auto &w:a)cout<<w<<' ';cout<<endl;
#define ALLN(x,n) begin(x), begin(x)+n
#define ALL(x) begin(x), end(x)
#define vec vector
#define snd second
#define fst first
#define pb push_back
#define ll long long
const ll MAX = 2e5+20, MOD = 1e9+7;
ll top = 100000000;

bool srt1(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b) {
    return a.first < b.first;
}

bool srt2(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b) {
    return a.first.second < b.first.second;
}

void solve(){        
    ll n;
    cin >> n;
    vector<pair<pair<ll, ll>, ll>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i + 1;
    }
    sort(ALL(a), srt1);
    multiset<pair<pair<ll, ll>, ll>> xl, xr, yl, yr;

    for(int i = 0; i < n; i++) {
        if(i < n / 2) {
            xl.insert(a[i]);
        }
        else xr.insert(a[i]);
    }
    sort(ALL(a), srt2);
    for(int i = 0; i < n; i++) {
        if(i < n / 2) {
            yl.insert(a[i]);
        }
        else yr.insert(a[i]);
    }

    multiset<pair<pair<ll, ll>, ll>> xlyl, xryr, ylxr, yrxl;
    for(auto i : xl) {
        if(yl.find(i) != yl.end()) {
            xlyl.insert(i);
        }
    }
    for(auto i : xr) {
        if(yr.find(i) != yr.end()) {
            xryr.insert(i);
        }
    }
    for(auto i : xl) {
        if(yr.find(i) != yr.end()) {
            yrxl.insert(i);
        }
    }
    for(auto i : xr) {
        if(yl.find(i) != yl.end()) {
            ylxr.insert(i);
        }
    }
    auto i = xlyl.begin();
    auto j = xryr.begin();
    while(i != xlyl.end()) {
        cout << i->second << ' ' << j->second << endl;
        i++;
        j++;
    }
    i = ylxr.begin();
    j = yrxl.begin();
    while(i != ylxr.end()) {
        cout << i->second << ' ' << j->second << endl;
        i++;
        j++;
    }   

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
        //cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}

