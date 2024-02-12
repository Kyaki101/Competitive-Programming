#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        int maxi = max(a, b);
        int mini = min(a, b);
        if(maxi % 2 != 0 && mini % 2 != 0)cout << "NO\n";
        else if(maxi % 2 == 0 && maxi / 2 == mini && mini % 2 != 0)cout << "NO\n";
        else cout << "YES\n";


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