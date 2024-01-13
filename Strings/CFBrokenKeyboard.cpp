/*
*Author: EmmanuelRojas
*Site: CodeForces
https://codeforces.com/problemset/problem/1907/B
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
typedef std::string str;
using namespace std;



str st;

str revStr(str & res){
    str novo = "";
    for(int i = res.size() - 1; i > -1; i--){
        novo += res[i];
    }
    return novo;
}

void sol(){
    cin >> st;
    int lower = 0;
    int upper = 0;
    str res = "";
    for(int i = st.size() - 1; i > -1; i--){
        if(st[i] == 'b'){
            lower ++;
        }
        else if(st[i] == 'B'){
            upper ++;
        }
        else if(st[i] < 'a'){
            if(upper == 0){

                res += st[i];
            }
            else {
                upper --;
            }
        }
        else if(st[i] >= 'a'){
            if(lower == 0){
                res += st[i];
            }
            else {
                lower --;
            }
        }
    }
    cout << revStr(res) << '\n';
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