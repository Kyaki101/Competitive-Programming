/*
*https://codeforces.com/problemset/problem/1858/A
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    
    int a, b, c;
    cin >> a >> b >> c;
    int half = 0;
    if(c & 1) half = c / 2 + 1;
    else half = c / 2;
    int first = half + a;
    int second = (c - half) + b;
    if(second >= first){cout << "Second\n"; return;}
    cout << "First\n";
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

