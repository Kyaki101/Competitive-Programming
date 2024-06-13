/*
*https://codeforces.com/contest/1985/problem/D
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;



void sol(){
    int n, m;
    cin >> n >> m;
    int a, b;
    char mat[n][m];
    bool bruh = false;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == '#' && !bruh){
                b = j + 1;
                bruh = true;
            }
            if(mat[i][j] == '#' && i + 1 == n){
                a = i + 1;
                cout << a << ' ' << b << endl;
                return;
            }
            if(mat[i][j] == '#' && mat[i + 1][j] != '#'){
                a = i + 1;
                cout << a << ' ' << b << endl;
                return;

            }
        }
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

