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
typedef pair<ll, ll> pll;

const int MAX = 2e5+20, MOD = 1e9+7;

void solve(){        
    ll n, m;
    cin >> n >> m;
    ll k = n + m + 1;
    vector<pll> a(k);
    for(int i = 0; i < k; i++) {
        cin >> a[i].first;
    }

    for(int i = 0; i < k; i++) {
        cin >> a[i].second;
    }
    set<pair<ll, pll>> p;
    set<pair<ll, pll>> t;
    ll pcount = 0, tcount = 0;
    for(int i = 0; i < k; i++) {
        if(a[i].first > a[i].second) {
            if(p.size() < n) {
                p.insert({i, a[i]});
                pcount += a[i].first;
            }
            else {
                t.insert({i, a[i]});
                tcount += a[i].second;
            }

        }
        else {
            if(t.size() < m) {
                t.insert({i, a[i]});
                tcount += a[i].second;
            }
            else {
                p.insert({i, a[i]});
                pcount += a[i].first;
            }

        }

    }
    pll floater = {0, 0};
    vll ans(k);


    for(int i = k - 1; i > -1; i--) {
        if(p.find({i, a[i]}) != p.end()) {
            pcount -= a[i].first;
        }
        else {
            tcount -= a[i].second;
        }
        p.erase({i, a[i]});
        t.erase({i, a[i]});
        if(floater == make_pair(0LL, 0LL)) {
            ans[i] = pcount + tcount;
            floater = a[i];
            continue;

        }
        if(floater.first > floater.second) {
            if(p.size() < n) {
                p.insert({i + 1, floater});
                pcount += floater.first;
            }
            else {
                if(n != 0 && (*p.begin()).first > i + 1) {
                    t.insert(*p.begin());
                    pcount -= (*p.begin()).second.first;
                    tcount += (*p.begin()).second.second;
                    p.erase(*p.begin());
                    p.insert({i + 1, floater});
                    pcount += floater.first;

                }
                else {
                    t.insert({i + 1, floater});
                    tcount += floater.second;
                }
            }
        }
        else if(t.size() < m) {
            t.insert({i + 1, floater});
            tcount += floater.second;
        }
        else {
            if(m != 0 && (*t.begin()).first > i + 1) {
                p.insert(*t.begin());
                tcount -= (*t.begin()).second.second;
                pcount += (*t.begin()).second.first;
                t.erase(*t.begin());
                t.insert({i + 1, floater});
                tcount += floater.second;

            }
            else {
                p.insert({i + 1, floater});
                pcount += floater.first;
            }
        }


        floater = a[i];

        ans[i] = pcount + tcount;

    }

    for(auto i : ans) cout << i << ' ';
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

