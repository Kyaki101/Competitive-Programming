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


bool cmp(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b) {
    ll x2 = (a.first.first) * (a.first.first);  
    ll x3 = (b.first.first) * b.first.first;

    ll y2 = a.first.second * a.first.second;
    ll y3 = b.first.second  * b.first.second;
    if(x2 + y2 != x3 + y3) {
        if(x2 + y2 < x3 + y3) return true;
        return false;
    }
    else if(a.first.first != b.first.first) {
        return a.first.first < b.first.first;
    }
    else {
        return a.first.second < b.first.second;
    }

}

void solve(){        
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n ; i++) {
        cin >> a[i];
    }


    vector<pair<pair<ll, ll>, ll> > tables;

    pair<ll, ll> curr = {0, 0};

    ll counter = 0;
    ll i = 0; 
    ll j = 0;
    ll index = 0;
    while(counter < n) {
        counter ++;
        curr = {j, i};
        tables.push_back({curr, 4});
        i --;
        j ++;
        if(i == -1) {
            index ++;
            i = index;
            j = 0;
        }

    }

    sort(ALL(tables), cmp);

    ll p = 0;
    ll w = 0;


    for(int i = 0; i < n; i++) {
        if(a[i] == 0) {
            cout << 3 * tables[p].first.first + 1 << ' ' << 3 * tables[p].first.second + 1;
            cout << endl;
            tables[p].second --;
            p++;
        }
        else {
            if(w == p) {
                p ++;
            }
            if(tables[w].second == 4) {

                cout << 3 * tables[w].first.first + 1 << ' ' << 3 * tables[w].first.second + 1;
            }

            else if(tables[w].second == 3) {

                cout << 3 * tables[w].first.first + 1 << ' ' << 3 * tables[w].first.second + 2;
            }
            else if(tables[w].second == 2) {
                
                cout << 3 * tables[w].first.first + 2 << ' ' << 3 * tables[w].first.second + 1;
            }
            else if(tables[w].second == 1) {
                cout << 3 * tables[w].first.first + 2 << ' ' << 3 * tables[w].first.second + 2;

            }

            cout << endl;
            tables[w].second --;
            if(tables[w].second == 0) w++;
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

