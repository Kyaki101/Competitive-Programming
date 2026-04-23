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

struct cmp {
    bool operator()(const pair<ll, bool>& a, const pair<ll, bool>& b) const {
        if (a.second) return true;
        if (b.second) return false;
        return a.first < b.first;
    }
};

void solve(){        
    ll n, k, p, m;
    cin >> n >> k >> p >> m;
    vll a(n);
    for(auto &i : a) cin >> i;
    multiset<pair<ll, bool>, cmp> nums;
    queue<pair<ll, bool>> cola;
    ll ans = 0;
    ll cost = 0;


    for(int i = 0; i < k; i++) {
        if(i == p - 1) {
            nums.insert({a[i], true});
            continue;
        }
        nums.insert({a[i], false});
    }
    for(int i = k; i < n; i++) {
        if(i == p - 1) {
            cola.push({a[i], true});
            continue;
        }
        cola.push({a[i], false});
    }

    while(cost + (*nums.begin()).first <= m) {
        pair<ll, bool> temp = *nums.begin();
        nums.erase(nums.begin());
        if(temp.second) ans++;
        cola.push(temp);
        nums.insert(cola.front());
        cola.pop();
        cost += temp.first;

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
        #ifdef ICPC 
            cout << "--------------------------------------------------" << endl;
        #endif // 
    }
    #ifdef ICPC 
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}

