#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    string s;
    cin >> s;
    int current = 1;
    ll counter = 0;
    for(int i = 0; i < 4; i++){
        counter += (abs(current - (s[i] - '0'))) + 1;
        current = s[i] - '0';
    }
    cout << counter << '\n';
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