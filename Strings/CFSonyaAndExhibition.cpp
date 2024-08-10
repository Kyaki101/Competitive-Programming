#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n, m;
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
    }
    string s = "";
    for(int i = 0; i < n; i++){
        if(i & 1) s+= '1';
        else s += '0';
    }
    cout << s << endl;
    
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

