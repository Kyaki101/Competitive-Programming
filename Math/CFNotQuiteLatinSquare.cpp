#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

vector<vector<char>> matrix;

void sol(){
    matrix.assign(3, vector<char>(3, ' '));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> matrix[i][j];
        }
    }
    for(int i = 0; i < 3; i++){
        if(matrix[i][0] == '?'){
            if(matrix[i][1] == 'A' && matrix[i][2] == 'B' || matrix[i][2] == 'A' && matrix[i][1] == 'B'){
                cout << "C\n"; return;
            }
            if(matrix[i][1] == 'A' && matrix[i][2] == 'C' || matrix[i][2] == 'A' && matrix[i][1] == 'C'){
                cout << "B\n"; return;
            }
            if(matrix[i][1] == 'B' && matrix[i][2] == 'C' || matrix[i][2] == 'B' && matrix[i][1] == 'C'){
                cout << "A\n"; return;
            }
        }
        else if(matrix[i][1] == '?'){
            if(matrix[i][0] == 'A' && matrix[i][2] == 'B' || matrix[i][2] == 'A' && matrix[i][0] == 'B'){
                cout << "C\n"; return;
            }
            if(matrix[i][0] == 'A' && matrix[i][2] == 'C' || matrix[i][2] == 'A' && matrix[i][0] == 'C'){
                cout << "B\n"; return;
            }
            if(matrix[i][0] == 'B' && matrix[i][2] == 'C' || matrix[i][2] == 'B' && matrix[i][0] == 'C'){
                cout << "A\n"; return;
            }
        }
        else if(matrix[i][2] == '?'){
            if(matrix[i][1] == 'A' && matrix[i][0] == 'B' || matrix[i][0] == 'A' && matrix[i][1] == 'B'){
                cout << "C\n"; return;
            }
            if(matrix[i][1] == 'A' && matrix[i][0] == 'C' || matrix[i][0] == 'A' && matrix[i][1] == 'C'){
                cout << "B\n"; return;
            }
            if(matrix[i][1] == 'B' && matrix[i][0] == 'C' || matrix[i][0] == 'B' && matrix[i][1] == 'C'){
                cout << "A\n"; return;
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