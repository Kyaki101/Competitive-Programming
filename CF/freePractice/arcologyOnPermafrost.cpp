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
    ll n, m, k;
    cin >> n >> m >> k;
    ll l = 0;
    ll r = n;

    auto buildArr = [&](ll jump) {
        ll curr = 0;
        vector<bool> vis(n);
        vll temp(n);
        for(int i = 0; i < n; i++) {
            if(vis[i]) break;
            for(int j = i; j < n; j += jump) {
                temp[j] = curr;
                vis[j] = true;
            }
            curr ++;
        }


        return temp;
    };

    auto check = [&](ll mid) {
        ll jump = max(k, mid + 1);
        vector<ll> freq(mid + 1);
        vector<ll> ans = buildArr(jump);

        // if(n == 8) {
        //     DEBUG(mid);
        //     for(auto i : ans) {
        //         cout << i << ' ';
        //     }
        // }
        // cout << endl;

        for(int i = 0; i < n; i++) {
            if(ans[i] <= mid) freq[ans[i]] ++;
        }
        if(freq[mid] <= m) {
            return false;
        }
        vector<bool> vis(n);
        ll bruh = m;

        for(int i = 0; i < n && bruh > 0; i++) {
            ll end = min(n, i + k);
            if(!vis[i] && ans[i] == 0) {
                bruh --;
                for(int j = i; j < end; j++) {
                    if(ans[j] <= mid) freq[ans[j]] --;
                    vis[j] = true;
                }
            }

        }

        for(int i = 0; i <= mid; i++) {
            if(!freq[i]) {
                return false;
            }
        }
        return true;
    };

    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    vll ans = buildArr(max(l + 1, k));

    for(auto i : ans) cout << i << ' ';
    cout << endl;




    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        #ifdef ICPC 
            cout << "--------------------------------------------------" << endl;
        #endif // 
    }
    #ifdef ICPC 
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}

