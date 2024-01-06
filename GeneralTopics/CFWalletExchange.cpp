#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

ll a, b;

void sol(){
    cin >> a >> b;
    if(!((a + b) & 1)){
        cout << "Bob\n"; return;
    }
    cout << "Alice\n";

}

int main(){
    int t;
    cin >> t;
    while(t--){
        sol();
    }


    return 0;
}