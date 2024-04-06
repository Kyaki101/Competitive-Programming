/*
*https://codeforces.com/problemset/problem/1360/A
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int a, b;
    cin >> a >> b;
    if(min(a, b) * 2 < max(a, b)){
        cout << max(a, b) * max(a, b) << endl;
        return;
    }
    int c = min(a, b) * 2;
    cout << c * c << endl;
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

