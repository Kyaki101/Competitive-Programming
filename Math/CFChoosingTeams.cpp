/*
*https://codeforces.com/problemset/problem/432/A
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n, c;
    cin >> n >> c;
    vec a(n, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int counter = 0;
    int gen = 0;
    for(int i = 0; i < n; i++){
        if(a[i] + c <= 5){
            counter ++;
        }
        if(counter == 3){
            counter = 0;
            gen ++;
        }
    }
    cout << gen << endl;
    
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

