/*
*https://codeforces.com/gym/105230/problem/H
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    string s;
    cin >> s;
    ll height = 0;
    ll maxi = 0;
    int index = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '+') height ++;
        else height --;
        if(height > maxi){
            maxi = height;
            index = i;
        }

    }
    cout << index + 1 << endl;
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

