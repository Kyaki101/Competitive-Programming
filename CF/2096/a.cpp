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
ll n;

void solve(){        
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll start = 1;


    for(int i = 0; i < n - 1; i++) {
        if(s[i] == '<') {
            start ++;
        }
    }
    ll larger = start + 1;
    cout << start << ' ';
    start --;
    for(int i = 0; i < n - 1; i++) {
        if(s[i] == '>') {
            cout << larger << ' ';
            larger ++;
        }
        else {
            cout << start << ' ';
            start --;
        }

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

