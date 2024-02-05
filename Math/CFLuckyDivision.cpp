/*
https://codeforces.com/problemset/problem/122/A
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

int divs[14] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};

void sol(){
    int n;
    cin >> n;
    for(int i = 0; i < 14; i++){
        if(n % divs[i] == 0){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";

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