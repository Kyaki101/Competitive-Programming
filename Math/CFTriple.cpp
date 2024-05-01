/*
*https://codeforces.com/contest/1669/problem/B
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    int temp;

    int mapa[200001] = {0};
    vec a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        mapa[a[i]] ++;
        if(mapa[a[i]] == 3){
            cout << a[i] << endl;
            return;
        } 
    }
    cout << -1 << endl;
    
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

