/*
*https://codeforces.com/problemset/problem/1535/A
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int first = max(a, b);
    int second = max(d, c);
    if(second < min(a, b) || first < min(c, d)){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    return;
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

