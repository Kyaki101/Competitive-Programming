#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int a, b, c;
    cin >> a >> b >> c;
    int scatter = (a + b + c) / 9;
    if(a < scatter || b < scatter || c < scatter){
        cout << "NO\n"; return;
    }
    cout << (((a + b + c) % 9 == 0)? "YES\n" : "NO\n");
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

