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
    string a, b;
    cin >> a >> b;
    int aones = 0, bones = 0;
    for (int i = 0; i < n; i++){
        ll pos = i + 1; 
        if(pos % 2 == 1) { 
            if(a[i] == '1')
                aones++;
        } else { 
            if(a[i] == '1')
                bones++;
        }
    }
    for (int i = 0; i < n; i++){
        ll pos = i + 1; 
        if(pos % 2 == 1) { 
            if(b[i] == '1')
                bones++;
        } else { 
            if(b[i] == '1')
                aones++;
        }
    }
    
    ll cap1 = n / 2;
    ll cap2 = n - (n / 2);
    
    if(aones <= cap1 && bones <= cap2) {
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
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

