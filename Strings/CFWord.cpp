/*
https://codeforces.com/problemset/problem/59/A
*/
#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    string s;
    cin >> s;
    int upC = 0;
    int loC = 0;
    for(char i : s){
        if(i < 95)upC ++;
        else loC++;
    }
    if(upC > loC){
        for(char & i : s){
            i = toupper(i);
        }
        cout << s << endl;
    }
    else{
        for(char & i : s){
            i = tolower(i);
        }
        cout << s << endl;;
    }
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