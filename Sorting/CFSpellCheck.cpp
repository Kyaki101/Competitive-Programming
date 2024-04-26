/*
*https://codeforces.com/contest/1722/problem/A
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
    string a = "Timur";
    sort(a.begin(), a.end());
    sort(s.begin(), s.end());
    if(a == s){
        cout << "YES\n";
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

