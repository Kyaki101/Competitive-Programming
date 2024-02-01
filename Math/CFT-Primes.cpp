/*
https://codeforces.com/problemset/problem/230/B
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

bool isPrime(ll a){
    if (a == 1)return false;
    for(ll i = 2; i * i <= a; i++){
        if(a % i == 0)return false;
    }
    return true;
}

bool isRound(long double a){
    if(round(a) == a){
        return true;
    }
    return false;
}

void sol(){
    int n;
    cin >> n;
    ll a;
    for(int i = 0; i< n; i++){
        cin >> a;
        long double sqr = sqrt(a);
        if(isPrime(sqr) && isRound(sqr)){
            cout << "YES\n";
        }
        else{cout << "NO\n";}
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