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
    ll n, q;
    cin >> n >> q;
    vector<string> a(n);
    map<string, vector<ll>> mapa;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mapa[a[i]].PB(i);
    }
    map<string, set<string>> bruh;
    bruh["BR"] = {"BG", "BY", "GR", "RY"};
    bruh["BG"] = {"BR", "BY", "GR", "GY"};
    bruh["BY"] = {"BR", "BG", "RY", "GY"};
    bruh["GR"] = {"BG", "GY", "BR", "RY"};
    bruh["GY"] = {"BY", "RY", "BG", "GR"};
    bruh["RY"] = {"BY", "GY", "BR", "GR"};

    auto check = [&](string i, string j) {
        return i[0] == j[0] || i[0] == j[1] || i[1] == j[0] || i[1] == j[1];
    };

    auto closest = [&](vector<ll> & nums, ll target, ll start) {
        ll size = nums.size();
        ll l = -1;
        ll r = size;
        while(l + 1 < r) {
            ll mid = (l + r) / 2;
            if(nums[mid] <= target) l = mid;
            else r = mid;
        }
        ll a1 = 0, a2 = 0;
        if(l == -1) {
            a1 = (1LL << 60);
        }
        else a1 = abs(start - nums[l]) + abs(nums[l] - target);

        l = -1;
        r = size;
        while(l + 1 < r) {
            ll mid = (l + r) / 2;
            if(nums[mid] >= target) r = mid;
            else l = mid;
        }
        if(r == size) a2 = (1LL << 60);
        else a2 = abs(start - nums[r]) + abs(nums[r] - target);
        return min(a1, a2);
    };

    while(q--) {
        ll i, j;
        cin >> i >> j;
        i --; j--;
        if(i > j) swap(i, j);

        if(check(a[i], a[j])) {
            cout << j - i << endl;
            continue;
        }
        ll mini = (1LL << 60);
        for(auto &s : bruh[a[i]]) {
            if(check(a[i], s) && mapa.find(s) != mapa.end()) {
                mini = min(mini, closest(mapa[s], j, i));
            }
        }
        if(mini == (1LL << 60)) cout << -1 << endl;
        else cout << mini << endl;
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

