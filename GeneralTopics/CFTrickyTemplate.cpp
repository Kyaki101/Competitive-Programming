#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

int n;
string a;
string b;
string c;

void sol(){
    cin >> n;
    cin >> a;
    cin >> b;
    cin >> c;
    for(int i = 0; i < n; i++){
        if(a[i] != c[i] && b[i] != c[i]){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";

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