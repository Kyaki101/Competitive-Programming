/*
https://codeforces.com/contest/1950/problem/B
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    vector<vector<char>> mat(2 * n, vector<char>(2 * n, '.'));

    for(int i = 0; i < n * 2; i++){
        for(int j = 0; j < n * 2; j++){
            if(i == 0 && j == 0){
                mat[i][j] = '#';
            }
            else if(i == 0){
                if(j & 1 && mat[i][j - 1] == '#'){
                    mat[i][j] = '#';
                }
                else if(!(j & 1) && mat[i][j - 1] == '.'){
                    mat[i][j] = '#';
                }
            }
            else if(mat[i - 1][j] == '#' && i == 1){
                mat[i][j] = '#';
            }
            else if(mat[i - 1][j] == '#' && mat[i - 2][j] == '.'){
                mat[i][j] = '#';
            }
            else if(mat[i - 1][j] == '.' && !(i & 1)){
                mat[i][j] = '#';
            }
        }
    }
    for(int i = 0; i < n * 2; i++){
        for(int j = 0; j < n * 2; j++){
            cout << mat[i][j];
        }
        cout << '\n';
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