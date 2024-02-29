#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    vec a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] %= 3;
        sum = (sum + a[i]) % 3;

    }
    if(!sum){
        cout << 0 << '\n';
        return;
    }
    if(sum == 2){
        cout << 1 << '\n';
        return;
    }
    if(sum == 1){
        for(int i = 0; i < n; i++){
            if(a[i] == 1){
                cout << 1 << '\n';
                return;
            }
        }
    }
    cout << 2 << '\n';
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