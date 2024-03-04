#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    vec a(n);
    vec b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[a[i] - 1] = i + 1;
    }
    for(int i = 0; i < n; i++){
        if(i == n - 1)cout << b[i] << endl;
        else cout << b[i] << ' ';
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