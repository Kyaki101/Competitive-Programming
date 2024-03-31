#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    string s;
    cin >> s;
    if(s.size() & 1){
        cout << "NO\n";
        return;
    }
    int i = 0;
    int j = s.size() / 2;
    while(j < s.size()){
        if(s[i] != s[j]){
            cout << "NO\n"; return;
        }
        j++;
        i++;
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
