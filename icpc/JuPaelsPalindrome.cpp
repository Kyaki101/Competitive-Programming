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
    string s;
    cin >> s;
    int maxi = 0;
    int mask = 0LL;
    vector<int> opts((1 << 26), -2);
    opts[mask] = -1;
    for(int i = 0; i < n; i++) {
        ll bit = s[i] - 'a';
        mask = mask ^ (1 << bit);
        if(opts[mask] != -2) {
            maxi = max(maxi, i - opts[mask]);
        }
        for(int j = 0; j < 26; j++) {
            int cpy = mask;
            if(opts[cpy ^ (1 << j)] != -2) {
                maxi = max(maxi, i - opts[cpy ^ (1 << j)]);
            }
        }
        if(opts[mask] == -2) {
            opts[mask] = i;
        }

    }
    cout << maxi << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

