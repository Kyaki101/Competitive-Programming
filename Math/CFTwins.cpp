/*
https://codeforces.com/problemset/problem/160/A
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

bool comp(int a, int b){
    return a > b;
}

ll getSum(vec & a){
    ll counter = 0;
    for(int i : a){
        counter += i;
    }
    return counter;
}

void sol(){
    int n;
    cin >> n;
    vec a(n, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end(), comp);
    ll sum = getSum(a);
    ll myCoins = 0;
    for(int i = 0; i < n; i++){
        myCoins += a[i];
        sum -= a[i];
        if(myCoins > sum){
            cout << i + 1 << endl;
            return;
        }
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