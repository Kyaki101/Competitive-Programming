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

void solve(){        
    ll n, m, r;
    cin >> n >> m >> r;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a[r - 1].push_back('*');
    reverse(ALL(a));

    ll index = 0;
    while(index < n) {

        bool flag = false;
        for(ll i = 0; i < m; i++) {
            if(a[index][i] == 'P') {
                flag = true;
                a[index][i] = 'X';
                string trash, result;
                cin >> trash >> result;
                ll improvement = 0;
                if(result != "Aaawww...") {
                    ll start = 6;
                    while(result[start] == 'y') {
                        improvement ++;
                        start ++;
                    }
                    if(improvement > 0) {
                        ll pos = index;
                        while(pos < improvement + index) {
                            swap(a[pos], a[pos + 1]);
                            pos++;
                        }

                    }

                }

                break;
            }

        }
        if(!flag) index ++;

    }
    reverse(ALL(a));



    for(int i = 0; i < n; i++) {
        if(a[i][m] == '*') {
            cout << i + 1 << endl;
            return;
        }
    }


}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}

