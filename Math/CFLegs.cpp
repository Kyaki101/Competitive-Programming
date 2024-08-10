/*
*https://codeforces.com/contest/1996/problem/A
*/



#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    int res = n / 4;
    n -= (n / 4) * 4;
    res += n / 2;
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

