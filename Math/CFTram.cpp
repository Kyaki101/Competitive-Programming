/*
*https://codeforces.com/problemset/problem/116/A
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    int a, b;
    int maxi = 0;
    int curr = 0;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        curr -= a;
        curr += b;
        maxi = max(maxi, curr);
    }
    cout << maxi << endl;
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
              
    int t;
    t = 1;
    while(t--){
        sol();
    }


    return 0;
}

