#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

int n;
string s;
string des;

void sol(){
    cin >> n;
    cin >> s;
    cin >> des;
    ll moves = 0;
    int cats = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1' && des[i] == '0'){
            cats ++;
        }
        if(s[i] == '0' && des[i] == '1'){
            moves ++;
            cats --;
        }
    }
    if(cats > 0){
        moves += cats;
    }
    cout << moves << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
              
    int t;
    cin >> t;
    while(t--){
        sol();
    }


    return 0;
}