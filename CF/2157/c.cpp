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

#define triple pair<ll, pair<ll, ll>>

const int MAX = 2e5+20, MOD = 1e9+7;

bool srt(triple a, triple b) {
    if(a.first != b.first) {
        return a.first > b.first;
    }
    return a.second.first < b.second.first;
}

void solve(){        
    ll n, k, q;
    cin >> n >> k >> q;
    vll a(n, -1);
    vector<bool> taken(n);
    vector<triple> qs;
    while(q --) {
        
        ll c, l , r;
        cin >> c >> l >> r;
        l --;
        r --;
        qs.PB({c, {l, r}});
    }
    sort(ALL(qs), srt);
    vector<bool> up(n, false);
    vector<bool> down(n, false);

    for(auto [c, f] : qs) {
        auto [l, r] = f;
        for(int i = l; i <= r; i++) {
            if(c == 1) up[i] = true;
            else down[i] = true;
        }

    }
    vector<bool> inter(n, false);
    for(int i = 0; i < n; i++) {
        if(up[i]&& down[i]) inter[i] = true;
    }

    for(auto [c, f] : qs) {
        auto [l, r] = f;

        if(c == 1) {
            for(int i = l; i <= r; i++) {
                if(!inter[i]) a[i] = k;
                else a[i] = 200;
            }
            continue;
        }
        set<ll> nums;
        for(int i = 0; i < k; i++) {
            nums.insert(i);
        }
        for(int i = l; i <= r; i++) {
            taken[i] = true;
            nums.erase(a[i]);
        }
        ll i = l;
        while(nums.size() != 0) {
            if(a[i] == -1 && !inter[i]) {
                a[i] = *nums.begin();
                nums.erase(nums.begin());
            }
            i++;
        }
    }


    for(int i = 0; i < n; i++) {
        if(a[i] == -1) a[i] = 0;
    }
    for(auto i : a) cout << i << ' ';
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

