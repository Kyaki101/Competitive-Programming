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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using OrderedSet = tree<
    T, null_type,
    std::less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

void solve(){        
    ll n, k;
    cin >> n >> k;
    OrderedSet<ll> nums;
    for(int i = 1; i <= n; i++) {
        nums.insert(i);
    }
    ll e = 0;
    auto it = nums.begin();
    while(nums.size() > 1) {
        ll mod = nums.size();
        e = (e + k) % mod;
        it = nums.find_by_order(e);
        cout << (*it) << ' ';
        nums.erase(it);
        if(e == nums.size()) {
            e = 0;
        }

    }
    cout << (*nums.begin()) << endl;

    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

