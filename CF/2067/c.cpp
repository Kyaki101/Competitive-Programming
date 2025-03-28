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

vector<ll> values(9);


void solve(){        

    ll n;
    cin >> n;
    string s = to_string(n);
    ll mini = 10;
    string num = "";
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '7') {
            cout << 0 << endl;
            return;
        }
    }


    for(int i = 0;i < s.size(); i++) {
        ll ori = stoll(s);
        num.push_back('9');
        for(int j = 1; j <= 9; j++) {
            ori += stoll(num); 
            string bruh = to_string(ori);
            for(int k = 0; k < bruh.size(); k++) {
                if(bruh[k] == '7') {
                    mini = min(mini, (ll) j);
                }
            }
        }

    }
    cout << mini << endl;

}

signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    values[0] = 3; values[1] = 4;
    values[2] = 5;
    values[3] = 6;
    values[4] = 7;
    values[5] = 8;
    values[6] = 9;
    values[7] = 0;
    values[8] = 1;
    values[9] = 2;
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

