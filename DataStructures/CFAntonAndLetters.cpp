/*
https://codeforces.com/problemset/problem/443/A
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    string s;
    getline(cin, s);
    set<char> se;
    for(char i : s){
        if(i != '{' && i != '}' && i != ',' && i != ' ') {
            se.insert(i);
        }
    }
    cout << se.size() << endl;
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