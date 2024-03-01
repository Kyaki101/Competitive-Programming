#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n, k;
    cin >> n >> k;
    int counter = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a > k) counter += 2;
        else counter ++;
    }
    cout << counter << '\n';
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