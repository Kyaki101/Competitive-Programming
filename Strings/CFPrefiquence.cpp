/*
*https://codeforces.com/contest/1968/problem/B
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    ll acount = 0;
    ll bcount = 0;
    ll af = 0;
    ll bf = 0;
    int cont = 0;
    int bPos = 0;
    for(int i = 0; i < n; i++){
        while(b[bPos] != a[i] && bPos < m){
            bPos++;
        }
        if(bPos == m){
            cout << cont << endl;
            return;
        }
        else{
            bPos++;
            cont ++;
        }
    } 
    cout << n << endl;
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

