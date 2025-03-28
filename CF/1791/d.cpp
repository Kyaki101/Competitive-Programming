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
    map<char, ll> right;
    map<char, ll> left;
    for(int i = 0; i < n; i++) {
        right[s[i]] ++;
    }

    ll maxi = 0;
    for(int i = 0; i < n; i++) {
        maxi = max(maxi, (ll)(right.size() + left.size()));
        left[s[i]] ++;
        right[s[i]] --;
        if(right[s[i]] == 0) right.erase(s[i]);
    }
    cout << maxi << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

