/*
https://codeforces.com/gym/104990/problem/A
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int a, b, c;
    cin >> a >> b >> c;
    int goal = a * c;
    int money = a;
    int months = 0;
    while(money < goal){
        money += b * (money / a);
        months ++;
    }
    cout << months << endl;
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