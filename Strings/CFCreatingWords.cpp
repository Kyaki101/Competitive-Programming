/*
*https://codeforces.com/contest/1985/problem/A
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    string a, b;
    cin >> a >> b;
    char bruh = a[0];
    a[0] = b[0];
    b[0] = bruh;
    cout << a << ' ' << b << '\n';
    
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

