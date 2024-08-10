/*
*https://codeforces.com/contest/1996/problem/B
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n, k;
    cin >> n >> k;
    vector<vector<char> > farm(n, vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> farm[i][j];
        }
    }
    for(int i = 0; i < n; i += k){
        for(int j = 0; j < n; j+= k){
            cout << farm[i][j];
        }
        cout << endl;
    }
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

