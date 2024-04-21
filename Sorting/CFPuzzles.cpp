/*
*https://codeforces.com/problemset/problem/337/A
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n, m;
    cin >> n >> m;
    vec puzzles(m);
    for(int i = 0; i < m; i++){
        cin >> puzzles[i];
    }
    int start = 0;
    int stop = n - 1;
    sort(puzzles.begin(), puzzles.end());
    int shortest = (1 << 30);
    while(stop < m){
        shortest = min(shortest, puzzles[stop] - puzzles[start]);
        start ++; stop++;
    }
    cout << shortest << endl;
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

