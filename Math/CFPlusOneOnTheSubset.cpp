/*
*https://codeforces.com/problemset/problem/1624/A
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
    int maxi = -1;
    int mini = (1 << 30);
    for(int i = 0; i < n; i++){
        maxi = max(maxi, a[i]);
        mini = min(mini, a[i]);
    }
    cout << (maxi - mini) << endl;
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

