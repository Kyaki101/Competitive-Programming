/*
*https://codeforces.com/problemset/problem/1972/A
*/



#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    
    int n;
    cin >> n;
    vec a(n);
    vec b(n);
    for(int i = 0; i < n; i++){ 
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){ 
        cin >> b[i];
    }
    int i = 0; int j = 0;
    int counter = 0;
    while(j < n){ 
        if(a[i] > b[j]){
            counter ++;
        }
        else{
            i++;
        }
        j++;
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

