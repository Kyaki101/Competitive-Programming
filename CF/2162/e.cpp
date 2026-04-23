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
    ll n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    set<ll> nums;
    for(int i = 1; i <= n; i++) {
        nums.insert(i);
    }
    for(auto i : a) nums.erase(i);
    if(nums.size() == 2) {
        vector<ll> ans;
        auto it = nums.begin();
        ans.PB(*it);
        it++;
        ans.PB(*it);
        ans.PB(a[n - 1]);
        ll ind = 0;
        while(k--) {
            cout << ans[ind] << ' ';
            ind ++;
            ind %= 3;
        }
        cout << endl;
        return;


    }
    if(nums.size() == 1) {
        if(n == 3 && a[0] == a[2]) {
            vector<ll> edge;
            edge.PB(*nums.begin());
            edge.PB(a[1]);
            edge.PB(a[2]);
            for(int i = 0; i < k; i++) {
                cout << edge[i] << ' ';
            }
            cout << endl;
            return;
            
        }
        if(n == 3 && a[0] == a[1]) {
            vector<ll> edge;
            edge.PB(*nums.begin());
            edge.PB(a[1]);
            edge.PB(a[2]);
            for(int i = 0; i < k; i++) {
                cout << edge[i] << ' ';
            }
            cout << endl;
            return;
        }
        if(n == 3 && a[1] == a[2]) {
            vector<ll> edge;
            edge.PB(*nums.begin());
            edge.PB(a[0]);
            edge.PB(a[1]);
            for(int i = 0; i < k; i++) {
                cout << edge[i] << ' ';
            }
            cout << endl;
            return;
        }

        cout << *nums.begin() << ' ';
        set<ll> pre;
        ll rep;
        for(auto i : a) {
            if(pre.find(i) != pre.end()) {
                rep = i;
                break;
            }
            pre.insert(i);
        }
        for(int i = 0; i < k - 1 && i < n; i++) {
            if(a[i] == rep) {
                k++;
                continue;
            }
            cout << a[i % n] << ' ';
        }
        if(k - 1 == n + 1) {
            cout << *nums.begin() << ' ';
        }
        cout << endl;
        return;


    }
    if(nums.size() == 0) {
        for(int i = 0; i < k; i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
        return;
    }
    vector<ll> bruh(ALL(nums));
    ll b = nums.size();
    ll index = 0;
    while(k--) {
        cout << bruh[index] << ' ';
        index ++;
        index %= b;
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

