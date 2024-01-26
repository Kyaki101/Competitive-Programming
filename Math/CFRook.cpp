#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

string sq;

void sol(){
    cin >> sq;
    int n = sq[1] - '0';
    for(int i = 1; i <= 8; i++){
        if(n != i){
            cout << sq[0] << i << endl;
        }
    }
    for(int i = 97; i <= 104; i++){
        if((char)(i) != sq[0]){
            cout << (char)(i) << n << endl;
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