int n;
#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    int a, b, c;
    int vertical = 0;
    int horizontal = 0;
    int deep = 0;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        vertical += a;
        horizontal += b;
        deep += c;

    }
    if(vertical == 0 && horizontal == 0 && deep == 0){cout << "YES\n"; return;}
    cout << "NO\n";
    
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