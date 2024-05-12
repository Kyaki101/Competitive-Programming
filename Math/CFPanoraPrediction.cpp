/*
*https://codeforces.com/problemset/problem/80/A
*/



#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;


bool isPrime(int n){
    if(n == 2 || n == 3)return true;
    if(n == 4 || n == 1)return false;
    if(!(n & 1))return false;
    int i = 3;
    while(i * i <= n){
        if(!(n % i)){
            return false;
        }
        i ++;
        i++;
    }
    return true;
}

void sol(){
    int n, m;
    cin >> n >> m;
    for(int i = n + 1; i < m; i++){
        if(isPrime(i)){
            cout << "NO\n";
            return;
        }
    }
    if(isPrime(m)){
        cout << "YES\n";
        return;
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

