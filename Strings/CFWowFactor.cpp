#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n, k;
    cin >> n >> k;
    int moves[n];
    for(int i = 0; i < n; i++){
        cin >> moves[i];
    }
    string s;
    cin >> s;
    char pre = ' ';
    int counter = 1;
    int ini, fin;
    ll dmg = 0;
    for(int i = 0; i < n; i++){
        if(s[i] != pre){
            ini = i;
            pre = s[i];
            counter = 1;
        }
        else counter += 1;
        
        if(i == n - 1 || s[i + 1] != s[i]){
            fin = i;
            if(counter > k){
                sort(moves + ini, moves + fin + 1, greater<int>());
                for(int j = ini; j < ini + k; j++){
                    dmg += moves[j];
                }
            }
            else{
                for(int j = ini; j <= fin; j++){
                    dmg += moves[j];
                }
            }
        }
        
    }
    cout << dmg << endl;

    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
              
    int t;
    t = 1;
    while(t--){
        sol();
    }


    return 0;
}

