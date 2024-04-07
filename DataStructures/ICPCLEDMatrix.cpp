/*
*https://codeforces.com/gym/105053/problem/L
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int r, c, k;
    cin >> r >> c >> k;
    vector<string> working, pat;
    working.assign(r, "");
    pat.assign(r, "");

    for(int i = 0; i < r; i++){
        cin >> working[i];
        cin >> pat[i];
    }
    vector<bool> w(r, true);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(working[i][j] == '-'){
                w[i] = false;
            }
        }
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < k; j++){
            if(pat[i][j] == '*'){
                if(!w[i]){
                    cout << "N\n";
                    return;
                }
            }
        }
    }
    cout << "Y\n";
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

