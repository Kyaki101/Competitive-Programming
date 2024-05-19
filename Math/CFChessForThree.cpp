/*
*https://codeforces.com/contest/1973/problem/A
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int a, b, c;
    cin >> a >> b >> c;
    if((a + b + c) & 1){
        cout << "-1\n";
        return;
    }
    if(c <= (a + b + c) / 2){
        cout << (a + b + c) / 2 << endl;
        return;
    }
    int sum = a + b + c;
    int diff = abs(sum / 2 - c / 2) * 2;
    if(c & 1){
        cout << diff - 1 << endl;
        return;
    }
    cout << diff << endl;
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

