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


bool straight(char sym, vector<string> & game) {
    if(game[0][0] == sym && game[1][0] == sym && game[2][0] == sym) return true;

    if(game[0][1] == sym && game[1][1] == sym && game[2][1] == sym) return true;

    if(game[0][2] == sym && game[1][2] == sym && game[2][2] == sym) return true;
    return false;
    
}

bool hor(char sym, vector<string> & game) {
    if(game[0][0] == sym && game[0][1] == sym && game[0][2] == sym) return true;

    if(game[1][0] == sym && game[1][1] == sym && game[1][2] == sym) return true;

    if(game[2][0] == sym && game[2][1] == sym && game[2][2] == sym) return true;
    return false;
    
}

bool diag(char sym, vector<string> & game) {
    if(game[0][0] == sym && game[1][1] == sym && game[2][2] == sym) return true;

    if(game[0][2] == sym && game[1][1] == sym && game[2][0] == sym) return true;

    return false;
}

void solve(){        
    vector<string> game(3);
    for(int i = 0; i < 3; i++) {
        cin >> game[i];
    }
    if(hor('+', game) || straight('+', game) || diag('+', game)) {
        cout << "+" << endl;
        return;
    }
    if(hor('O', game) || straight('O', game) || diag('O', game)) {
        cout << "O" << endl;
        return;
    }
    if(hor('X', game) || straight('X', game) || diag('X', game)) {
        cout << "X" << endl;
        return;
    }
    cout << "DRAW" << endl;
    return;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

