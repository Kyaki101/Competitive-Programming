#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename Key, typename Value>
using ordered_map = tree<Key, Value, less<Key>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename Key, typename Value = null_type>
using trie = trie<Key, Value, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update>;
#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) (cout << (n) << endl)
#define CLEAN(arr) (memset(arr, 0, sizeof(arr)))
#define ALL(v) (v).begin(), (v).end()


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

const int MAX = 2e5+20;

bool inTime(vector<vector<ll> > & a, ll index, ll time, ll baloons) {
    return baloons * a[index][0] + ((baloons - 1) / a[index][1]) * a[index][2] <= time;
}

void sol(){        
    ll b, n;
    cin >> b >> n;
    vector<vector<ll> > a(n, vector<ll>(3));
    for(int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    ll minTime;
    ll r = (1LL << 60);
    ll l = -1;

    while(l + 1 < r) {
        ll ball = 0;
        ll midTime = (l + r) / 2;
        for(int i = 0; i < n; i++){
        ll l2 = 0;
        ll r2 = b + 1;
        while(l2 + 1 < r2) {
            ll midBalloons = (l2 + r2) / 2;
            if(inTime(a, i, midTime, midBalloons)) {
                l2 = midBalloons;
            }
            else r2 = midBalloons;
            
        }
            ball += l2;
        }

        if(ball >= b) {
            r = midTime;
        }
        else l = midTime;
    }
    minTime = r;
    cout << minTime << endl;
    vector<ll> ans(n);
 
 
    for(int i = 0; i < n; i++) {
        ll left = 0;
        ll right = b + 1;
        while(left + 1 < right) {
            ll ma = (left + right) / 2;
            if(inTime(a, i, minTime, ma)) {
                left = ma;
            }
            else right = ma;
 
        }
        ans[i] = left;
    }
    ll sum = 0;
    for(ll i : ans) {
        if(sum + i <= b) {
            cout << i << ' ';
            sum += i;
        }
        else {
            cout << b - sum << ' ';
            sum = b;
        }
 
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

              
    int t;
    t = 1;
    while(t--){
        sol();
    }


    return 0;
}

