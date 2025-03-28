#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
typedef long long int ll;
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

void solve(){        
    ll n, m, k;
    cin >> m >> n >> k;
    if(n < k && m < k || abs(n - m) > k) {
        cout << -1 << endl;
        return;
    }
    string s = "";
    if(m >= n) {
        for(int i = 0; i < k; i++) {
            s.push_back('0');
            m --;
        }
        bool one = true;
        ll bruh = n + m;
        for(int i = 0; i < bruh; i++) {
            if(one && n || !m) {
                s.push_back('1');
                one = false;
                n --;
            }
            else s.push_back('0'), m--, one = true;
        }

        cout << s << endl;
        return;

    }
    for(int i = 0; i < k; i++) {
        s.push_back('1');
        n --;
    }
    bool zero = true;
    ll bruh = n + m;
    for(int i = 0; i < bruh; i++) {
        if(zero && m || !n) {
            s.push_back('0');
            zero = false;
            m --;
        }
        else s.push_back('1'), n--, zero = true;
    }
    cout << s << endl;
    return;


}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

