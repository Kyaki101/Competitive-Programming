/*
*https://codeforces.com/problemset/problem/1829/B
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
    int counter = 0;
    int maxi = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            counter += 1;
            maxi = max(counter, maxi);
        }
        else{
            counter = 0;
        }
    }
    cout << maxi << endl;
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

