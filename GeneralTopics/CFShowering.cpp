/*
*https://codeforces.com/contest/1999/problem/C
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n, s, k;
    cin >> n >> s >> k;
    vec intervals(n * 2 + 1);
    intervals[0] = 0;
    for(int i = 1; i <= n * 2; i++){
        cin >> intervals[i];
    }
    intervals.push_back(k);
    for(int i = 0; i <= n * 2; i ++, i++){
        if(intervals[i + 1] - intervals[i] >= s){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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

