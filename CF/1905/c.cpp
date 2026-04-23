#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define F second
#define S first
#define PB push_back
#define ll long long
typedef vector<ll> vll;

const int MAX = 2e5+20, MOD = 1e9+7;

void solve(){        
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<ll, char>> suff(n);
    suff[n - 1] = {n - 1, s[n - 1]};

    for(int i = n - 2; i > -1; i--) {
        if(s[i] >= suff[i + 1].second) suff[i] = {i, s[i]};
        else suff[i] = suff[i + 1];
    }

    string bruh = "";
    vector<ll> poses;
    for(int i = 0; i < n; i++) {
        bruh.push_back(suff[i].second);
        i = suff[i].first;
        poses.push_back(i);
    }


    ll tam = bruh.size();
    ll res = 0;
    ll pointer = 0;

    while (bruh.front() != bruh.back()) {
        s[poses[pointer]] = bruh.back();
        pointer ++;
        bruh.pop_back();
        res++;
    }
    for(auto i : bruh) {
        s[poses[pointer]] = i;
        pointer ++;
    }

    if(is_sorted(ALL(s))) {
        cout << res << endl;
        return;
    } 

    cout << -1 << endl;


    
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

