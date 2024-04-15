/*
*https://codeforces.com/problemset/problem/1760/A
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int a, b, c;
    cin >> a >> b >> c;
    int maxim = max(a, b);
    int minim = min(a, b);
    if(c > maxim){
        cout << maxim << '\n';
        return;
    }
    if(c < minim){
        cout << minim << '\n';
        return;
    }
    cout << c << endl;
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

