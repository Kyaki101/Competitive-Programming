/*
*https://codeforces.com/contest/1997/problem/C
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string fix = "";
    int counter = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '_' && !counter){
            fix += '(';
            counter ++;
        }
        else if(s[i] == '_' && counter){
            fix += ')';
            counter --;
        }
        else if(s[i] == '('){
            counter ++;
            fix += '(';
        }
        else if(s[i] == ')'){
            counter --;
            fix += ')';
        }
        
    }
    stack< int > pila;
    int res = 0;
    for(int i = 0; i < n; i++){
        if(fix[i] == '('){
            pila.push(i);
        }
        else{
            res += i - pila.top();
            pila.pop();
        }
    }
    cout << res << endl;
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

