/*
*https://codeforces.com/group/5GNF7zti59/contest/535722/problem/M
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;


int sumar(int * milk, int n){
    int suma = 0;
    for(int i = 0; i < n; i += 2){
        suma += milk[i];

    }
    return suma;
}

void sol(){
    int n, h;
    cin >> n >> h;
    int milk[n];
    int res = 0;
    for(int i = 0; i < n; i++) cin >> milk[i];
   

    for(int i = 0; i < n; i++){
        sort(milk, milk + i + 1, greater<int>()); 
        int pre = sumar(milk, i + 1);
        if(pre > h){
            cout << i << endl;
            return;
        }
        res = pre;
        
        
    }
    cout << n << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
              
    int t;
    t=1;
    while(t--){
        sol();
    }


    return 0;
}

