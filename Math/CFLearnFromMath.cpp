/*
*https://codeforces.com/problemset/problem/472/A
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

bool prime(int n){
    if(n == 0) return false;
    if(n == 1) return false;
    if(n == 2) return true;
    if(n == 3) return true;
    int i = 3;
    if(!(n & 1)) return false;
    while(i * i <= n){
        if(n % i == 0){
            return false;
        }
        i++;
    }
    return true;
}

void sol(){
    int n;
    cin >> n;
    int j = 4;
    int i = n - 4;
    while(true){
        if(!prime(i) && !prime(j)){
            cout << j << ' ' << i << '\n';
            return;
        }
        i --;
        j ++;
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

