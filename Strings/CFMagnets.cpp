/*
*https://codeforces.com/problemset/problem/344/A
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    string a;
    string b;
    cin >> a;
    int counter = 1;
    for(int i = 0; i < n - 1; i++){
        cin >> b;
        if(a[1] == b[0]) counter ++;
        a = b;

    }
    cout << counter << endl;
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

