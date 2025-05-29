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
ll n;


pair<ll, ll> findNum(ll p, ll x, ll added, ll i, ll j) {
    if(p == 0) {
        if(added == x) return {i, j};
        if(added + 1 == x) return {i + 1, j + 1};
        if(added + 2 == x) return {i + 1, j};
        return {i, j + 1};
    }
    ll four = pow(4, p);
    ll two = pow(2, p);
    if((added - 1) + four >= x) {
        return findNum(p - 1, x, added, i, j);
    }
    if((added - 1) + four * 2 >= x) {
        return findNum(p - 1, x, added + four, i + two, j + two);
    }
    if((added - 1) + four * 3 >= x) {
        return findNum(p - 1, x, added + four * 2, i + two, j);
    }
    return findNum(p - 1, x, added + four * 3, i, j + two);

}


ll coord(ll i, ll j, ll number, ll p, ll x, ll y) {
    // cout << x + 1 << ' ' << y << " | " << i << ' ' << j << " | " << number << endl;
    if(p == 0) {
        if(i == x && j == y) return number;
        if(x + 1 == i && y + 1 == j) return number + 1;
        if(x + 1 == i && j == y) return number + 2;
        return number + 3;
    }

    ll two = pow(2, p);
    ll four = pow(4, p);

    if((x - 1) + two >= i && (y - 1) + two >= j) {
        return coord(i, j, number, p - 1, x, y);
    }

    if((x - 1) + two * 2 >= i && (y - 1) + two >= j) {
        return coord(i, j, number + four * 2, p - 1, x + two, y);
    }

    if((x - 1) + two >= i && (y - 1) + two * 2 >= j) {
        return coord(i, j, number + four * 3, p - 1, x, y + two);
    }
    
    return coord(i, j, number + four, p - 1, x + two, y + two);


}


void solve(){        
    ll n;
    cin >> n;
    ll q;
    cin >> q;
    while(q --) {
        string s;
        cin >> s;
        ll x, y;
        if(s == "->") {
            cin >> x >> y;
            cout << coord(x, y, 1, n - 1, 1, 1) << endl;;
        }
        else {
            cin >> x;
            pair<ll, ll> bruh = findNum(n - 1, x, 1, 1, 1);
            cout << bruh.first << ' ' << bruh.second << endl;
            
        }

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

