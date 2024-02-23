#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    string s;
    cin >> s;
    ll c = 0;
    for(char i : s){
        if(i == '4' || i == '7') c++;
    }
    string num = to_string(c);
    for(char i : num){
        if(i != '4' && i != '7'){
            cout << "NO\n"; return;
        }
    }
    cout << "YES\n";
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