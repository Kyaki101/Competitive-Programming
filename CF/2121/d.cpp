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
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    vector<ll> b(n);
    for(auto &i: b) cin >> i;
    map<ll, ll> mapa;
    ll curr = 1;
    for(int i = 0; i < n; i++) {
        mapa[curr] = i;
        curr += 2;
    }
    curr = 2;
    for(int i = 0; i < n; i++) {
        mapa[curr] = i;
        curr += 2;
    }
    vector<pair<ll, ll>> steps;
    for(int num = 1; num <= n * 2; num++) {
        ll pos = -1;
        bool place = true;
        for(int i = 0; i < n; i++) {
            if(a[i] == num) pos = i;
        }
        if(pos == -1) for(int i = 0; i < n; i++) {
            if(b[i] == num) pos = i;
            place = false;
        }
        if(num % 2 == 0 && place || num % 2 == 1 && !place) {
            swap(a[pos], b[pos]);
            steps.push_back({3, pos + 1});
        }
        if(num % 2 == 0) place = false;
        else place = true;

        while(pos > mapa[num]) {
            if(place) {
                swap(a[pos], a[pos - 1]);
                steps.push_back({1, pos});
                pos --;
            }
            else {
                swap(b[pos], b[pos - 1]);
                steps.push_back({2, pos});
                pos --;
            }

        }
    }
    cout << steps.size() << endl;
    for(auto i : steps) {
        cout << i.first << ' ' << i.second << endl;
    }

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

