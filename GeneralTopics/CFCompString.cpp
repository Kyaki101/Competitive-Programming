#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll res = 0;
    ll counter = 1;
    char pre = s[0];
    for(int i = 1; i < n; i++){
        if(s[i] == s[i-1]){
            counter ++;
        }
        else {
            res = max(counter, res);
            pre = s[i];
            counter = 1;
        }
    }
    res = max(counter, res);
    cout << res + 1 << '\n';

}

int main(){
    int t;
    cin >> t;
    while(t--){
        sol();
    }


    return 0;
}