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
    ll n, p;
    cin >> n >> p;
    vector<string> words(n);
    for(int i = 0; i < n; i++) {
        cin >> words[i];
    }
    vector<string> numbers(p);
    for(int i = 0; i < p; i++) {
        cin >> numbers[i];
    }
    map<char, set<ll> > mapa;
    mapa['2'].insert('a');

    mapa['2'].insert('b');

    mapa['2'].insert('c');


    mapa['3'].insert('d');

    mapa['3'].insert('e');

    mapa['3'].insert('f');


    mapa['4'].insert('g');

    mapa['4'].insert('h');

    mapa['4'].insert('i');

    mapa['5'].insert('j');

    mapa['5'].insert('k');

    mapa['5'].insert('l');


    mapa['6'].insert('m');

    mapa['6'].insert('n');

    mapa['6'].insert('o');


    mapa['7'].insert('p');

    mapa['7'].insert('q');

    mapa['7'].insert('r');

    mapa['7'].insert('s');



    mapa['8'].insert('t');

    mapa['8'].insert('u');

    mapa['8'].insert('v');


    mapa['9'].insert('w');

    mapa['9'].insert('x');

    
    mapa['9'].insert('y');


    mapa['9'].insert('z');



    vector<vector<string>> ans(p);


    for(int i = 0; i < p; i++) {
        for(int j = 0; j < n; j++) {

            bool flag = true;
            if(numbers[i].size() != words[j].size()) continue;
            for(int k = 0; k < words[j].size(); k++) {
                if(mapa[numbers[i][k]].find(words[j][k]) == mapa[numbers[i][k]].end()) {
                    flag = false;
                }
            }

            if(flag) {
                ans[i].push_back(words[j]);
            }
        }
    }

    for(int i = 0; i < p; i++) {
        cout << ans[i].size();
        for(auto j : ans[i]) {
            cout << ' '<< j;
        }
        cout << endl;
    }





}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}

