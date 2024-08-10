/*
*https://codeforces.com/contest/1997/problem/A
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    string s;
    cin >> s;
    bool flag = true;
    if(s.size() == 1){
        if(s[0] == 'a'){
            cout << 'a' << 'b';
        }
        else cout << s[0] << 'a';
        cout << endl;
        return;
    }
    for(int i = 0; i < s.size() - 1; i++){
        if(s[i] == s[i + 1] && flag){
            if(s[i] == 'z') cout << s[i] << 'a';
            else cout << s[i] << 'z';
            flag = false;
        }
        else cout << s[i];
    }
    cout << s[s.size() - 1];
    if(flag){
        if(s[s.size() - 1] == 'z'){
            cout << 'a';
        }
        else cout << 'z';
    }
    cout << endl;
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

