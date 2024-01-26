/*
https://codeforces.com/gym/104921/problem/F
*/

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
        int c = s[i] - '0';
        if(c == 0)c = 10;
        counter += (abs(current - c)) + 1;
        current = c;
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