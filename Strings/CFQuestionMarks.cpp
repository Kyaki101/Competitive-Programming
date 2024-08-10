/*
*https://codeforces.com/contest/1993/problem/A
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l[5] = {0};
    int res = 0;
    for(int i = 0; i < n * 4; i++){
        if(s[i] != '?'){
            l[s[i] - 'A'] ++;
        }
    }
    for(int i = 0; i < 4; i++){
        if(l[i] <= n){
            res += l[i];
        }
        else res += n;
    }
    cout << res << endl;
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

