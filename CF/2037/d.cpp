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

void solve(){        
    ll n, m, goal;
    cin >> n >> m >> goal;

    vector<pair<pair<ll, ll>, ll> > locations;

    for(int i = 0; i < n; i++) {
        ll l, r;
        cin >> l >> r;
        locations.push_back({{l, r}, 1});
    }

    for(int i = 0; i < m; i++) {
        ll l, p;
        cin >> l >> p;
        locations.push_back({{l, p}, 0});
    }
    sort(ALL(locations));

    vector<pair<ll, bool> > bruh;
    for(int i = 0; i < n + m; i++) {
        if(locations[i].second == 1) {
            bruh.push_back({abs(locations[i].first.first - locations[i].first.second) + 2, 1});
        }
        else {
            bruh.push_back({locations[i].first.second, 0});
        }
    }

    priority_queue<ll> powers;
    ll jump = 1;
    ll count = 0;



    for(int i = 0; i < bruh.size(); i++) {
        if(bruh[i].second == 0) {
            powers.push(bruh[i].first);
        }
        else {
            while(!powers.empty() && jump < bruh[i].first) {
                count ++;
                jump += powers.top();
                powers.pop();

            }

            if(jump < bruh[i].first) {
                cout << -1 << endl;
                return;
            }
        }
    }

    cout << count << endl;


}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

