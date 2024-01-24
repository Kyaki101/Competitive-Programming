#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    string a, b;
    cin >> a >> b;
    for(char & i : a){
        i = tolower(i);
    }
    for(char & i : b){
        i = tolower(i);
    }
    int Acounter = 0;
    int Bcounter = 0;
    for(int i = 0; i < a.size(); i++){
        Acounter += a[i] - 'a';
        Bcounter += b[i] - 'a';
        if(Acounter > Bcounter){cout << "1\n"; return;}
        if(Bcounter > Acounter){cout << "-1\n"; return;}
    }
    cout << "0\n";
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