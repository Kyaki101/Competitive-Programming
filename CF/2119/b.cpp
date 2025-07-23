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

void solve(){        
    ll n;
    cin >> n;
    ll p1, p2, q1, q2;
    cin >> p1 >> p2 >> q1 >> q2;
    vector<double> a(n);
    for(auto &i : a) cin >> i;
    double distance = sqrt((p1 - q1) * (p1 - q1) + (p2 - q2) * (p2 - q2));
    a.push_back(distance);
    sort(ALL(a));
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        a[n] -= a[i];
    }
    if(a[n] <= 0) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;

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

