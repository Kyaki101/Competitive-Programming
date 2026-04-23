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

void findNum(ll num, vector<string> &opts, string& curr, ll currSum, multiset<ll> & avail) {
    bool bruh = false;
    for(char i = '1'; i < '9' + 1; i++) {
        if(avail.find(i) == avail.end()) {
            continue;
        }

        if(currSum + (i - '0') == num) {
            opts.PB(curr + i);
            return true;
        }

        if(currSum = (i - '0') < num) {
            curr.PB(i);
            currSum += i - '0';
            avail.erase(avail.find(i));
            bruh = bruh || findNum(num, opts, curr, currSum, avail);
            curr.pop_back(i);
            avail.insert(i);
        }

    }
    return bruh;

}

vector<string> ans;

bool srch(string number, multiset<ll> & avail) {
    if(avail.size() == 0) return true;
    num = stoll(number);
    bool bruh = false;

    vector<string> opts;
    string curr = "";
    if(findNum(num, opts, curr, 0, avail)) {
        for(auto & opt : opts) {
            for(auto i : opt) avail.erase(avail.find(i));
            bruh || srch(opt, avail);
            for(auto i : opt) avail.insert(i);
        }

    }
    return bruh;

}

void solve(){        
    ll n;
    string s;
    cin >> s;
    ll z = 0;
    multiset<ll> avail;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') z++;
        else avail.insert(s[i]);
    }

    
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

