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
        ll a;
        cin >> a;
        sum += abs(a);
    }
    cout << sum << endl;
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