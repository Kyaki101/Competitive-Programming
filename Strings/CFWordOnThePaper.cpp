/*
https://codeforces.com/gym/104921/problem/C
*/
#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

vector<vector<char>> mat;

void sol(){
    mat.assign(8, vector<char>(8, ' '));
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> mat[i][j];
        }
    }

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(mat[i][j] != '.'){
                while(i < 8 && mat[i][j] != '.'){
                    cout << mat[i][j];
                    i++;
                }
                cout << '\n';
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