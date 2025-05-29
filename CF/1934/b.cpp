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
    if(n % 15 == 0) {
        cout << n / 15 << endl;
        return;
    }
    ll count = 0;
    if(n % 3 == 1) {
        if(n >= 10) {
            n -= 10;
            count ++;
        }
        else {
            count += n / 6;
            n -= 6 * (n / 6);
            count += n / 3;
            n -= 3 * (n / 3);
            count += n;
            cout << count << endl;
            return;
        }
    }
    if(n % 3 == 2) {
        if(n >= 20) {
            count += 2;
            n -= 20;
        }
        else {
            count += n / 15;
            n -= 15 * (n / 15);
            count += n / 10;
            n -= 10 * (n / 10);
            count += n / 6;
            n -= 6 * (n / 6);
            count += n / 3;
            n -= 3 * (n / 3);
            count += n;
            cout << count << endl;
            return;
        }
    }

    if(n == 0) {
        cout << count << endl;
        return;
    }
    if(n % 15 == 0) {
        cout << count + n / 15 << endl;
        return;
    }
    if(n % 15 == 3 || n % 15 == 6) {
        cout << count + (n / 15) + 1 << endl;
        return;
    }
    cout << count + (n / 15) + 2 << endl;

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

