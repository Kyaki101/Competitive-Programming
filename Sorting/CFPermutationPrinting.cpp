/*
https://codeforces.com/contest/1930/problem/B
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    vec a;
    for(int i = n; i >= 1; i--){
        a.push_back(i);
    }
    vec res;
    int i = 0;
    int j = n -1;
    while(i <= j){
        res.push_back(a[i]);
        i++;
        if(i <= j){
            res.push_back(a[j]);
            j--;
        }
    }
    //3 2 1
    for(int i : res)cout << i << ' ';
    cout << endl;
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