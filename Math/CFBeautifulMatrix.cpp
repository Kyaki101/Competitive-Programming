#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

vector<vec> mat;

void sol(){
    mat.assign(5, vec(5, 0));
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> mat[i][j];
            if(mat[i][j] == 1){
                int res = (abs(i - 2) + abs(j - 2));
                cout << res << '\n';
            }
        }
    }
    
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