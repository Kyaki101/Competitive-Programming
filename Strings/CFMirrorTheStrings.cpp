#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    string s;
    cin >> n >> s;
    int i = 1;
    char greatest = s[0];
    string res = "";
    if(n == 1){
        cout << s[0] << s[0] << endl;
        return;
    }
    if(s[0] == s[1]){
        cout << s[0] << s[0] << endl;
        return;
    }
    res += s[0];
    while(s[i] <= greatest && i < n){
        res += s[i];
        greatest = s[i];
        i++;
    }
    cout << res;
    reverse(res.begin(), res.end());
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

