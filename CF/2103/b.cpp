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
    string s;
    cin >> n >> s;
    string b = "";
    b.push_back('0');
    ll val = 0;
    char curr = '0';
    for(int i = 0; i < n; i++) {

        if(s[i] == curr) val ++;
        else {
            curr = s[i];
            val += 2;
        }

    }
    char prev = '0';
    for(int i = 0; i < n; i++) {
        if(s[i] != prev) {
            prev = s[i];
            b.push_back(s[i]);
        }
    }
    ll len = b.size();
    for(int i = 0; i <= len - 3; i++) {
        if(b.substr(i, 3) == "101") {
            cout << val - 2 << endl;
            return;
        }
    }
    for(int i = 0; i <= len - 3; i++) {
        if(b.substr(i, 3) == "010") {
            cout << val - 1 << endl;
            return;
        }
    }
    cout << val << endl;
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

