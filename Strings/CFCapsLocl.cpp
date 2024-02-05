#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    string s;
    cin >> s;
    bool flag = true;
    for(int i = 1; i < s.size(); i++){
        if((int)(s[i]) > 96){
            flag = false;
        }
    }
    if(flag){

        for(char i : s){
            if (i > 96)cout << (char)toupper(i);
            else(cout << (char)(tolower(i)));
        }
        cout << '\n';
    }
    else cout << s << endl;
    

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