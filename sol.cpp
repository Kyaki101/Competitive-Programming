/*
*https://codeforces.com/contest/1980/problem/B
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n, f, k;
    cin >> n >> f >> k;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int fav = arr[f - 1];
    int cantFavs = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == fav) cantFavs ++;
    }
    sort(arr, arr + n, greater<int>());
    int left = 0;
    for(int i = k; i < n; i++){
       if(arr[i] == fav){
            left ++; 
        } 
    }
    if(!left){
        cout << "YES\n"; return;
    }
    if(left < cantFavs){
        cout << "MAYBE\n"; return;
    }
    cout << "NO\n";
    
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

