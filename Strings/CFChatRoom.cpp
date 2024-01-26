#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    string s;
    cin >> s;
    string h = "hello";
    int ui = 0;
    for(char i : s){
        if(ui < 5 && i == h[ui]){
            ui ++;
        }
    }
    if(ui == 5){cout << "YES\n"; return;}
    cout << "NO\n";
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