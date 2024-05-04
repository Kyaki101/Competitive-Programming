/*
*https://codeforces.com/contest/1968/problem/C
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    
    int n;
    int maxi = 1000;
    cin >> n;
    vec a(n - 1);
    for(int i = 0; i < n - 1; i++){
        cin >> a[i];
    }
    cout << maxi << ' ';  

    for(int i = 0; i < n - 1; i++){
        if(i == n - 2){
            cout << maxi + a[i] << '\n';
            return;
        }
        cout << maxi + a[i] << " ";
        maxi += a[i];
    }




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

