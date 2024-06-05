/*
*https://codeforces.com/contest/1980/problem/A
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int arr[7] = {0};
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++){
        arr[s[i] - 'A'] ++;
    }
    int cont = 0;
    for(int i = 0; i < 7; i++){
        if(arr[i] < m){
            cont += m - arr[i];
        }
    }
    cout << cont << endl;
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

