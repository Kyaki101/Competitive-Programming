/*
*https://codeforces.com/problemset/problem/200/B
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    int a;
    cin >> n;
    int counter = 0;
    for(int i = 0; i < n; i++){
        cin >> a;
        counter += a;
    }
    cout << (counter * 1.0) / (n * 1.0) << endl;
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

