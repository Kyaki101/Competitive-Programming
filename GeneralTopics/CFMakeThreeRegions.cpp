/*
*https://codeforces.com/contest/1997/problem/B
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int counter = 0;
    for(int i = 1; i < n - 1; i++){
        if(a[i] == '.' && a[i - 1] == '.' && a[i + 1] == '.' && b[i] == '.' && b[i - 1] == 'x' && b[i + 1] == 'x'){ counter ++; }
        if(b[i] == '.' && b[i - 1] == '.' && b[i + 1] == '.' && a[i] == '.'  && a[i - 1] == 'x' && a[i + 1] == 'x'){ counter ++; }
    }
    cout << counter << endl;
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

