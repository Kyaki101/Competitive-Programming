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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    set<string> words;
    ll counter = 1;
    string pre = s.substr(0, 2);
    words.insert(pre);
    reverse(ALL(pre));
    words.insert(pre);
    for(int i = 1; i < n - 1; i++) {
        string bruh = s.substr(i, 2);
        if(words.find(bruh) == words.end()) {
            counter ++;
            words.clear();
            words.insert(bruh);
            reverse(ALL(bruh));
            words.insert(bruh);
        }
    }
    cout << counter << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

