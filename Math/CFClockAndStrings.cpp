/*
*https://codeforces.com/contest/1971/problem/C
*/



#include <bits/stdc++.h>
using namespace std;


int t, x, y, a, b;



int main(){

  cin>>t;
  while(t--){
    
    cin>>a>>b>>x>>y;
    if(((x > max(a, b) || x < min(a, b)) && !(y > max(a, b) || y < min(a, b))) || ((y > max(a, b) || y < min(a, b)) && !(x > max(a, b) || x < min(a, b)))) cout<<"YES\n";
    else cout<<"NO\n";
  
  }return 0;
}
