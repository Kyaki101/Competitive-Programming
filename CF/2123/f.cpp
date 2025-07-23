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

vector<bool> sieve(MAX, false);

void solve(){        
    ll n;
    cin >> n;
    vector<vector<ll>> mults(n + 1);
    vector<ll> ans(n + 1, 0);
    ans[1] = 1;
    vector<bool> vis(n + 1, false);
    for(int i = n; i >= 2; i--) {
        if(!sieve[i]) for(int j = i; j <= n; j += i) {
            if(!vis[j]) {
                mults[i].push_back(j);
                vis[j] = true;
            }
        }
    }
    // for(int i = 1; i <= n; i++) {
    //     if(!sieve[i]) {
    //         reverse(ALL(mults[i]));
    //         if(mults[i].size() & 1 && mults[i].size() > 1) {
    //             swap(mults[i][mults[i].size() / 2], mults[i][mults[i].size() / 2 + 1]);
    //         }
    //     }
    // }
    for(int i = 2; i <= n; i++) {
        if(!sieve[i]) {
            ll l = 0;
            ll r = mults[i].size() -1;
            if(mults[i].size() == 1) {
                ans[i] = i;
                continue;
            }

            if((mults[i].size() & 1) && mults[i].size() > 1) {
                while(r - l > 2) {
                    ans[mults[i][r]] = mults[i][l];
                    ans[mults[i][l]] = mults[i][r];
                    l ++;
                    r --;
                }
                ans[mults[i][l + 1]] = mults[i][l];
                ans[mults[i][r]] = mults[i][l + 1];
                ans[mults[i][l]] = mults[i][r];
            }
            else {
                while(l < r) {
                    ans[mults[i][r]] = mults[i][l];
                    ans[mults[i][l]] = mults[i][r];
                    l ++;
                    r --;

                }
            }

        }
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;


}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    sieve[0] = true; sieve[1] = true;
    for(int i = 2; i * i <= MAX; i++) {
        if(!sieve[i]) for(int j = 2 * i; j < MAX; j += i){
            sieve[j] = true;
        }
    }
    while(t--){
        solve();
    }return 0;
}

