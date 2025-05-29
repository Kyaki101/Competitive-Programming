#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
template<typename T>
using ordered_set = tree<T, null_type, greater<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

template<typename T>
using ordered_set_x = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;



bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    if(a.first != b.first) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

void solve(){        
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    map<pair<ll, ll>, ll> mapa;
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        mapa[a[i]] = i;
    }
    sort(ALL(a), cmp);
    ordered_set<pair<ll, ll>> os;
    vector<ll> under(n);
    for(int i = 0; i < n; i++) {
        ll overMe = os.order_of_key({a[i].second, n - i});
        os.insert({a[i].second, n - i});
        under[mapa[a[i]]] = overMe;
    }
    ordered_set_x<pair<ll, ll>> ms;
    vector<ll> ova(n);
    for(int i = n - 1; i > -1; i--) {
        ll overTake = ms.order_of_key({a[i].second, n - i});
        ova[mapa[a[i]]] = overTake;
        ms.insert({a[i].second, n - i});

    }
    for(auto i : ova) {
        cout << i << ' ';
    }
    cout << endl;
    for(auto i : under) {

        cout << i << ' ';
    }
    cout << endl;



}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

