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

bool check(string & a, string & b) {
    multiset<char> letters;
    for(auto i : b) letters.insert(i);
    for(auto i : a) {
        if(letters.find(i) == letters.end()) {
            return false;
        }
        letters.erase(letters.find(i));
    }
    return true;

}

void solve(){        
    string a, b;
    cin >> a >> b;
    ll n = a.size(), m = b.size();
    if(!check(a, b)) {
        cout << "Impossible" << endl;
        return;
    }
    priority_queue<char, vector<char>, greater<char>> pq;
    multiset<char> chars;
    for(auto i : b) chars.insert(i);
    for(auto i : a) chars.erase(chars.find(i));
    string ans = "";
    for(int i = 0; i < n; i++) {
        while(chars.size() != 0 && *chars.begin() < a[i]) {
            ans.PB(*chars.begin());
            chars.erase(chars.begin());
        }
        ans.PB(a[i]);
    }
    while(chars.size() != 0) {
        ans.PB(*chars.begin());
        chars.erase(chars.begin());
    }
    cout << ans << endl;
    
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

