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

void solve(){        
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll suma = 0;
    for(ll &i : a) {
        cin >> i;
        suma += i;
    }

    set<ll> nums;
    ll num = 0;
    vector<ll> ans1(n);
    for(int i = 0; i < n; i++) {
        if(a[i] > num && nums.find(a[i]) != nums.end()) {
            num = a[i];
        }
        nums.insert(a[i]);
        ans1[i] = num;
        suma += ans1[i];

    }

    nums.clear();
    num = 0;
    vector<ll> ans2(n);
    for(int i = 0; i < n; i++) {
        if(ans1[i] > num && nums.find(ans1[i]) != nums.end()) {
            num = ans1[i];
        }
        nums.insert(ans1[i]);
        ans2[i] = num;
    }


    for(int i = 0; i < n; i++) {
        suma += ans2[i] * (n - i);
    }

    cout << suma << endl;

    



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

