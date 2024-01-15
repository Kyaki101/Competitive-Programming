#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<bool> li(26, false);
              
    string w;
    cin >> w;
    for(int i = 0; i < w.size(); i++){
        li[w[i] - 'a'] = true;
    }
    ll counter = 0;
    for(int i = 0; i < 26; i++){
        if(li[i]) counter ++;
    }
    if(counter & 1) cout << "IGNORE HIM!\n";
    else cout << "CHAT WITH HER!\n";
    return 0;
}