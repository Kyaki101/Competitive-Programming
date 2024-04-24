/*
*https://codeforces.com/problemset/problem/580/A
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    
    int n;
    cin >> n;
    int curr = 0;
    int longest = 0;
    int j = -1;
    vec a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        if(a[i] >= j){
            curr ++;
            longest = max(longest, curr);
        }
        else{
            curr = 1;
            longest = max(longest, curr);
        }
        j = a[i];
    }
    cout << longest << '\n';
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

