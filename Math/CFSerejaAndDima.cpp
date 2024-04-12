/*
*
*https://codeforces.com/problemset/problem/381/A
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    
    int n;
    cin >> n;
    vec a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int i = 0; int j = n - 1;
    int turn = 0;
    int c = 0;
    int d = 0;
    while(i <= j){
        if(a[i] > a[j]){
            if(turn & 1){
                d += a[i];
            }
            else c += a[i];
            i++;
        }
        else if(a[j] >= a[i]){
            if(turn & 1){
                d += a[j];
            }
            else c+= a[j];
            j--;
        }
        turn ++;
    }
    cout << c << ' ' << d << endl;
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

