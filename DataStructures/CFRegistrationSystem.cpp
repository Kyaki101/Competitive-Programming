/*
https://codeforces.com/problemset/problem/4/C
*/
#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    string s;
    unordered_map<string, int> dataBase;
    for(int i = 0; i < n; i++){
        cin >> s;
        auto it = dataBase.find(s);
        if(it == dataBase.end()){
            cout << "OK\n";
            dataBase[s] = 0;
        }
        else{
            dataBase[s] ++;
            cout << s << dataBase[s] << '\n';
        }
    }

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