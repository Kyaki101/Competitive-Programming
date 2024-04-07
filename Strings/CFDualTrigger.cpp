/*
*https://codeforces.com/contest/1951/problem/A
*
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
    int counter = 0;
    bool flag = false;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            if(i > 0 && s[i - 1] == '1') flag = true;
            counter ++;
        }
    }
    if(!(counter & 1)){
        if(counter == 2 && flag){
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
    return;

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

