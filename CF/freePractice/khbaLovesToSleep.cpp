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


struct tel {
    ll lefty;
    ll righty;
    ll pos;
    bool dir;

};

ll getDist(const tel &a) {
    if(a.dir) return a.righty - a.pos;
    return a.pos - a.lefty;


}

struct cmp {
    bool operator()(const tel &a, const tel &b) const {
        return getDist(a) < getDist(b);
    }
};

void solve(){        
    ll n, x, k;
    cin >> n >> k >> x;
    vll a(n);
    for(auto &i : a) cin >> i;
    sort(ALL(a));
    priority_queue<tel, vector<tel>, cmp> cola;

    cola.push({0, a[0], 0, true});
    cola.push({a[n - 1], x, x, false});
    for(int i = 0; i < n - 1; i++) {
        if((a[i + 1] - a[i]) % 2 == 1) {
            cola.push({a[i], a[i + 1], (a[i] + a[i + 1]) / 2, false});
            cola.push({a[i], a[i + 1], (a[i] + a[i + 1]) / 2 + 1, true});


        }
        else {
            cola.push({a[i], a[i + 1], (a[i + 1] + a[i]) / 2, true});
            cola.push({a[i], a[i + 1], (a[i + 1] + a[i]) / 2 - 1, false});
        }

    }


    set<ll> vis;

    while(k--) {
        auto temp = cola.top();
        cola.pop();
        if(vis.find(temp.pos) != vis.end()) {
            k++;
            continue;
        }

        vis.insert(temp.pos);
        if(temp.dir && temp.pos == temp.righty) continue;
        if(!temp.dir && temp.pos == temp.lefty) continue;
        if(temp.dir) {
            temp.pos ++;
        }
        else {
            temp.pos --;
        }

        if(vis.find(temp.pos) == vis.end()) cola.push(temp);
    }

    for(auto i : vis) {
        cout << i << ' ';
    }
    cout << endl;


    
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

