#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

int n;

string s;

vec alfa;



void sol(){
    cin >> n;
    alfa.assign(26, 0);
    cin >> s;
    for(int i = 0; i < n; i++){
        alfa[s[i] - 'a'] ++;
    }
    int mx = 0;
    for(int i = 0; i < 26; i++){
        mx = max(mx, alfa[i]);
    }
    cout << max(n % 2, 2 * mx - n) << '\n';
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