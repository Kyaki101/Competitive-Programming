/*
https://codeforces.com/problemset/problem/155/A
*/
#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    vec a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int maxi = a[0];
    int mini =  a[0];
    int count = 0;
    for(int i = 1; i < n; i++){
        if(a[i] > maxi){
            count ++;
            maxi = a[i];
        }
        else if(a[i] < mini){
            count ++;
            mini = a[i];
        }
    }
    cout << count << endl;
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