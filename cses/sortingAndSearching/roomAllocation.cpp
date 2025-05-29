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

void solve(){        
    ll n;
    cin >> n;
    vector<pair<pair<ll, ll>, ll>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i;
    }
    sort(ALL(a));
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    ll rooms = 0;
    vector<ll> room(n);
    for(int i = 0; i < n; i++) {
        if(pq.empty()) {
            rooms ++;
            pq.push({a[i].first.second, rooms});
            room[a[i].second] = rooms;
            continue;
        }
        if(pq.top().first >= a[i].first.first) {
            rooms ++;
            pq.push({a[i].first.second, rooms});
            room[a[i].second] = rooms;
            continue;
        }
        else {
            room[a[i].second] = pq.top().second;
            pq.pop();
            pq.push({a[i].first.second, room[a[i].second]});
        }

    }
    cout << rooms << endl;
    for(auto &i : room) {
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

