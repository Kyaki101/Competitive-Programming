
#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int a, b, n;
    cin >> n;

    int c = 0;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        if(a < b - 1)c++;
    }
    cout << c << endl;
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