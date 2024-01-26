/*
https://codeforces.com/gym/104921/problem/D
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

int n, m;

vector<vector<char>> mat;

void sol(){
    cin >> n >> m;
    string word = "vika";
    mat.assign(n, vector<char>(m, ' '));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    int index = 0;
    for(int i = 0; i < m; i++){
        bool flag = true;
        for(int j = 0; j < n; j++){
            if(mat[j][i] == word[index] && flag && index < 4){
                index ++;
                flag = false;
            }
        }
    }
    if(index == 4){
        cout << "YES\n"; return;
    }
    cout << "NO\n";
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