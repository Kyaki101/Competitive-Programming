/*
*https://codeforces.com/contest/1986/problem/D
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    if(s.size() == 2){
        cout << stoi(s) << endl;
        return;
    }
    if(s.size() == 3 && s[0] != '0' && s[1] == '0' && s[2] != '0'){
        if(s[2] == '1'){
            cout << s[0] << endl;
            return;
        }
        if(s[0] == '1'){
            cout << s[2] << endl;
            return;
        }
        else{
            int res = s[0] - '0';
            res += s[2] - '0';
            cout << res << endl;
            return;
        }
    }
    int counter = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            cout << "0\n";
            return;
        }
        if(s[i] != '1') counter += s[i] - '0';
    }
    int res = (1 << 30);
    for(int i = 0; i < n - 1; i++){
        int rem = 0;
        if(s[i] != '1'){
            rem += s[i] - '0';
        }  
        if(s[i + 1] != '1'){
            rem += s[i + 1] - '0';
        }
        string number = "";
        number += s[i]; number += s[i + 1];
        res = min(stoi(number) + (counter - rem), res); 
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

