/*
https://codeforces.com/gym/104921/problem/E
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

int n;

void sol(){
    cin >> n;
    if(n % 3){
        cout << "First\n"; return;
    }
    cout << "Second\n";
    
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