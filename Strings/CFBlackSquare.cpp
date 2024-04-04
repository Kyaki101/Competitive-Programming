/*
*https://codeforces.com/problemset/problem/431/A
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    string s = "";
    cin >> s;
    int counter = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1'){
            counter += a;
        }
        if(s[i] == '2'){
            counter += b;
        }
        if(s[i] == '3'){
            counter += c;
        }
        if(s[i] == '4'){
            counter += d;
        }
    }
    cout << counter << '\n';
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

