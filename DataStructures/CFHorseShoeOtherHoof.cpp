/*
https://codeforces.com/problemset/problem/228/A
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    set<int> shoes;
    shoes.insert(a);
    int counter = 0;
    if(shoes.find(b) == shoes.end()){
        shoes.insert(b);
    }
    else counter ++;
        if(shoes.find(c) == shoes.end()){
        shoes.insert(c);
    }
    else counter ++;
        if(shoes.find(d) == shoes.end()){
        shoes.insert(d);
    }
    else counter ++;
    cout << counter << endl;
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