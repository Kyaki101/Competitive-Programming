/*
*
*https://codeforces.com/problemset/problem/686/A
*/



#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    long long int n, x;
    cin >> n >> x;
    char symb;
    long long int ice;
    long long int dist = 0;
    for(int i = 0; i < n; i++){
        cin >> symb >> ice;
        if(symb == '-'){
            if(ice <= x) x -= ice;
            else dist ++;
        }
        else{
            x += ice;
        }
    }
    cout << x << ' ' << dist << endl;
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

