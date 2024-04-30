/*
*https://codeforces.com/problemset/problem/702/A
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
    int longest = 1;
    int curr = 1;
    for(int i = 1; i < n; i++){
        if(a[i] > a[i - 1]){
            curr ++;
            longest = max(curr, longest);
        }
        else{
            curr = 1;
        }
    }
    cout << longest << endl;
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

