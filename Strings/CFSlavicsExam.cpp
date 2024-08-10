/*
*https://codeforces.com/contest/1999/problem/D
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    string s;
    cin >> s;
    string b;
    cin >> b;
    int pos = 0;
    for(int i = 0; i < s.size(); i++){
        if(pos < b.size()){
            if(s[i] == b[pos]) pos++;
            else if(s[i] == '?'){
                s[i] = b[pos];
                pos ++;
            }
        }
        else if(s[i] == '?') s[i] = 'a';
    }
    if(pos == b.size()){
        cout << "YES\n";
        cout << s << endl;
        return;
    }
    cout << "NO\n";
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

