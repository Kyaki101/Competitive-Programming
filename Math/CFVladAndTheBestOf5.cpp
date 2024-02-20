/*
https://codeforces.com/contest/1926/problem/A
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    string s;
    cin >> s;
    int acounter = 0;
    int bcounter = 0;
    for(char i : s){
    i == 'A'? acounter++ : bcounter++;
    }
    acounter > bcounter? cout << "A\n" : cout << "B\n";
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