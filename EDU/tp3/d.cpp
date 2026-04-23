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

ll dist(ll a, ll b) {
    return abs(a - b);
}

pair<ll, vll> four(vll & pivot, vll & o1, vll &o2, vll &o3) {
    ll n1 = pivot.size();
    ll n2 = o1.size();
    ll n3 = o2.size();
    ll n4 = o3.size();
    ll j = 0;
    ll k = 0;
    ll w = 0;
    ll mini = (1 << 30);
    vll ans;
    for(int i = 0; i < n1; i++) {
        while(j < n2 - 1 && dist(o1[j + 1], pivot[i]) <= dist(o1[j], pivot[i])) {
            j++;
        }
        while(k < n3 - 1 && dist(o2[k + 1], pivot[i]) <= dist(o2[k], pivot[i])) {
            k++;
        }
        while(w < n4 - 1 && dist(o3[w + 1], pivot[i]) <= dist(o3[w], pivot[i])) {
            w++;
        }
        ll fish = max(max(pivot[i], o1[j]), max(o2[k], o3[w]));
        ll bruh = min(min(pivot[i], o1[j]), min(o2[k], o3[w]));
        if(fish - bruh < mini) {
            mini = fish - bruh;
            ans = {i, j, k, w};
        }
    }
    return {mini, ans};
}

void solve(){        
    ll n1, n2, n3, n4;

    cin >> n1;
    vector<ll> a1(n1);
    for(auto &i : a1) cin >> i;

    cin >> n2;
    vll a2(n2);
    for(auto &i : a2) cin >> i;

    cin >> n3;
    vll a3(n3);
    for(auto &i : a3) cin >> i;

    cin >> n4;
    vll a4(n4);
    for(auto &i : a4) cin >> i;
    
    sort(ALL(a1));
    sort(ALL(a2));
    sort(ALL(a3));
    sort(ALL(a4));

    ll mini = (1 << 30);
    vll ans;
    pair<ll, vll> bruh;
    ll chosen;

    bruh = four(a2, a1, a3, a4);
    if(bruh.first < mini) {
        mini = bruh.first;
        ans = bruh.second;
        chosen = 0;
    }

    bruh = four(a3, a2, a1, a4);
    if(bruh.first < mini) {
        mini = bruh.first;
        ans = bruh.second;
        chosen = 1;
    }
    
    bruh = four(a4, a2, a3, a1);
    if(bruh.first < mini) {
        mini = bruh.first;
        ans = bruh.second;
        chosen = 2;
    }

    bruh = four(a1, a2, a3, a4);
    if(bruh.first < mini) {
        mini = bruh.first;
        ans = bruh.second;
    }
    if(chosen == 0) {
        cout << a1[ans[1]] << ' ' << a2[ans[0]] << ' ' << a3[ans[2]] << ' ' << a4[ans[3]] << endl;
        return;
    }
    if(chosen == 1) {
        cout << a1[ans[2]] << ' ' << a2[ans[1]] << ' ' << a3[ans[0]] << ' ' << a4[ans[3]] << endl;
        return;
    }
    if(chosen == 2) {
        cout << a1[ans[3]] << ' ' << a2[ans[1]] << ' ' << a3[ans[2]] << ' ' << a4[ans[0]] << endl;
        return;
    }   

    cout << a1[ans[0]] << ' ' << a2[ans[1]] << ' ' << a3[ans[2]] << ' ' << a4[ans[3]] << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

