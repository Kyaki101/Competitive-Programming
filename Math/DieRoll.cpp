/*
*https://codeforces.com/problemset/problem/9/A
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int a, b;
    cin >> a >> b;
    int num = 7 - max(a, b);
    if(num == 1){
        cout << "1/6\n";
        return;
    }
    if(num == 2){
        cout << "1/3\n";
        return;
    }
    if(num == 3){
        cout << "1/2\n";
        return;
    }
    if(num == 4){
        cout << "2/3\n";
            return;
    }
    if(num == 5){
        cout << "5/6\n";
        return;
    }
    if(num == 6){
        cout << "1/1\n";
        return;
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

