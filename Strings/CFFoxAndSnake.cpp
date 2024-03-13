#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;


string gensn(int n, int m, bool flag){
    if(!(n & 1)){
        string r = "";
        for(int i = 0; i < m; i++){
            r += '#';
            
        }
        return r;
    }
    if(flag){
        string r = "";
        for(int i = 0; i < m - 1; i++){
            r += '.';
        }
        r += '#';
        return r;
    }
    string r = "";
    r += '#';
    for(int i = 1; i < m; i++){
        r += '.';
    }
    return r;

}   

void sol(){
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    bool flag = true;
    for(int i = 0; i < n; i++){
        a[i] = gensn(i, m, flag);
        if(i & 1 && flag == false && i > 1)flag = true;
        else if(i & 1 && flag == true)flag = false;
    }
    for(string i : a){
        cout << i << '\n';
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