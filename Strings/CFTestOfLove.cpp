/*
*https://codeforces.com/contest/1992/problem/D
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    ll n, m, k;    
    cin >> n >> m >> k;
    string s;
    cin >> s;
    s = "L" + s + "L";
    n += 2;
    m --;
    ll jump = m;

    ll swim = k;
    for(int i = 0; i < n; i++){
        if(s[i] == 'L'){
            jump = m;
        }
        if(s[i] == 'W' && jump > 0){
            jump --;
        }

        else if(s[i] == 'W' && !swim){
            cout << "NO\n";
            return;
        }      

        else if(s[i] == 'W'){
            swim --;
        }
        
        if(s[i] == 'C' && jump){
            jump --;
        }
        else if(s[i] == 'C'){
            cout << "NO\n";
            return;
        }

    }
    cout << "YES\n";

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

