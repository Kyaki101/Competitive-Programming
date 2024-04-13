/*
*
*https://codeforces.com/problemset/problem/703/A
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    int a, b;
    int aw = 0;
    int bw = 0;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        if(a > b)aw++;
        if(b > a)bw++;
    }
    if(aw > bw){
        cout << "Mishka\n";
        return;
    }
    if(bw > aw){
        cout << "Chris\n";
        return;
    }
    cout << "Friendship is magic!^^\n";
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

