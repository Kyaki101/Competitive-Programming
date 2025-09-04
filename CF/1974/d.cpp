#include <bits/stdc++.h>
using namespace std;

#define SET(m,i) ((m)|(1ULL<<(i)))
#define TEST(m,i) ((m)&(1ULL<<(i)))
#define CLEAR(m,i) ((m)&~(1ULL<<(i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define DEBUG_ALL(a) for(auto &w:a)cout<<w<<' ';cout<<endl;
#define ALLN(x,n) begin(x), begin(x)+n
#define ALL(x) begin(x), end(x)
#define vec vector
#define snd second
#define fst first
#define pb push_back
#define ll long long
const ll MAX = 2e5+20, MOD = 1e9+7;

void solve(){        
    ll n;
    cin >> n;
    string s;
    cin >> s;
    unordered_map<char, ll> mapa;
    for(auto i : s) mapa[i]++;
    ll horDiff = abs(mapa['E'] - mapa['W']);
    ll vertDiff = abs(mapa['N'] - mapa['S']);
    if((horDiff & 1) || (vertDiff & 1)) {
        cout << "NO" << endl;
        return;
    }
    if(mapa['E'] == mapa['W'] && mapa['N'] == mapa['S']) {
        if(mapa['E'] == 0 && mapa['N'] == 1 || mapa['E'] == 1 && mapa['N'] == 0) {
            cout << "NO" << endl;
            return;
        }
        if(mapa['E'] >= 1) {
            bool picked = false;
            bool pi = false;
            for(auto i : s) {
                if(!picked && i == 'E') {
                    picked = true;
                    cout << 'R';
                    continue;
                }
                if(!pi && i == 'W') {
                    pi = true;
                    cout << 'R';
                    continue;
                }
                cout << 'H';

            }
            cout << endl;

        }
        else {
            bool picked = false;
            bool pi = false;
            for(auto i : s) {
                if(!picked && i == 'N') {
                    picked = true;
                    cout << 'R';
                    continue;
                }
                if(!pi && i == 'S') {
                    pi = true;
                    cout << 'R';
                    continue;
                }

                cout << 'H';
            }
            cout << endl;

        }
        return;
    }
    unordered_map<char, ll> rover, heli;
    if(mapa['E'] > mapa['W']) {
        rover['E'] += horDiff / 2;
        heli['E'] += horDiff / 2;
        mapa['E'] = mapa['W'];
        heli['E'] += mapa['E'];
        heli['W'] += mapa['W'];
    }
    else {
        rover['W'] += horDiff / 2;
        heli['W'] += horDiff / 2;
        mapa['W'] = mapa['E'];
        heli['E'] += mapa['E'];
        heli['W'] += mapa['W'];    }

    if(mapa['N'] > mapa['S']) {
        rover['N'] += vertDiff / 2;
        heli['N'] += vertDiff / 2;
        mapa['N'] = mapa['S'];
        heli['N'] += mapa['N'];
        heli['S'] += mapa['S'];
    }
    else {
        rover['S'] += vertDiff / 2;
        heli['S'] += vertDiff / 2;
        mapa['S'] = mapa['N'];
        heli['S'] += mapa['S'];
        heli['R'] += mapa['R']; 
    } 
    for(auto i : s) {
        if(rover[i] == 0) {
            cout << 'H';
            heli[i] --;
        }
        else {
            cout << 'R';
            rover[i] --;
        }
    }
    cout << endl;
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
        //cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}

