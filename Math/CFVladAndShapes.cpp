/*
https://codeforces.com/contest/1926/problem/B
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    vector<string> a(n, "");
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == '1'){
                if(a[i][j] == '1' && a[i][j+1] == '1' && a[i+1][j] == '1'){
                cout << "SQUARE\n"; return;
                }
                else{
                    cout << "TRIANGLE\n";
                    return;
                }
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