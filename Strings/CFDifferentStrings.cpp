/*
*https://codeforces.com/contest/1971/problem/B
*/



#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    string s;
    cin >> s;
    char j = s[0];
    for(int i = 1; i < s.size(); i++){
        if(s[i] != s[0]){
            s[0] = s[i];
            s[i] = j;
            cout << "YES\n";
            cout << s << endl;
            return;
        }
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

